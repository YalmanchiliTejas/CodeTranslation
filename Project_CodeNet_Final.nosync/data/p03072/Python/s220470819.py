n = int(input())
h = list(map(int,input().split()))
ans = 0
pre = h[0]
for i in range(n):
  if pre <= h[i]:
    ans += 1
  pre = max(pre,h[i])
print(ans)