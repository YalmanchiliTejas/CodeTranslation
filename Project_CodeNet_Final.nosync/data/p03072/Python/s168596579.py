n = int(input())
ma = 0
ans = 0
for i in map(int, input().split()):
  if ma <= i:
    ans += 1
  ma = max(ma, i)
print(ans)