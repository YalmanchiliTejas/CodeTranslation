n = int(input())
a = list(map(int,input().split()))
mx = 0
c = 0
for i in range(n):
  if a[i] >= mx:
    c += 1
    mx = a[i]
print(c)
  