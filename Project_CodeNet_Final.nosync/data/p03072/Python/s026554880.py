n = int(input())
h = list(map(int, input().split()))
ma = 0
ans = 0
for i in h:
  if ma <= i:
    ans += 1
  ma = max([ma, i])

print(ans)