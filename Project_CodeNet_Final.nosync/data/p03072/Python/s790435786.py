n = int(input())
hlist = list(map(int, input().split()))

maxh = 0
ans = 0
for h in hlist:
  if h >= maxh:
    ans += 1
    maxh = h
print(ans)
