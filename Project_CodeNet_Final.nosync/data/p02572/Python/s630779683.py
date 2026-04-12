n = int(input())
a = list(map(int,input().split()))

p = 10 ** 9 + 7

suma = 0
dsum = 0
for i in a:
  suma = (suma + i) % p
  dsum = (dsum + i ** 2) % p

sa2 = (suma ** 2) % p
ans2 = (sa2 - dsum) % p
if ans2 % 2  == 0:
  ans = ans2 // 2
else:
  ans = (ans2+p) // 2
print(ans)