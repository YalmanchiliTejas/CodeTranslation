n = int(input())
a = list(map(int, input().split()))
m = a[0]
ans = 1
for i in range(1,n):
  if m <= a[i]:
    ans += 1
    m = a[i]
print(ans)