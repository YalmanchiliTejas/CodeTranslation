n = int(input())
a = list(map(int, input().split()))
res = 0
for i in range(n):
  if a[i] >= a[0]:
    res += 1
    a[0] = a[i]
print(res)