n = int(input())
hs = list(map(int, input().split()))

ans = 1

for i in range(1, n):
  pre = hs[:i]
  if max(pre) <= hs[i]:
    ans += 1
print(ans)
