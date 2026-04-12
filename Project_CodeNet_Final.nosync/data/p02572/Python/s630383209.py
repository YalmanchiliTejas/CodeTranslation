n = int(input())
a = list(map(int,input().split()))

s = 0
for i in range(n):
  s += a[i]
  #sはaの和

t = 0
for i in range(n):
  t += a[i]**2
  #tはaの2乗和

ans = ((s**2 - t)//2) % (10**9 + 7)
print(ans)