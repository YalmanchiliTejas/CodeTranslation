n = int(input())
a = list(map(int,input().split()))
c, mx = 1, a[0]
for i in range(1,n):
  if a[i] >= mx:
    mx = a[i]
    c += 1
print(c)
