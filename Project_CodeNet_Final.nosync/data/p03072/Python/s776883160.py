n = int(input())
tmp = 0
ans = 0
for h in map(int, input().split()):
  if tmp <= h:
    ans += 1
    tmp = h
print(ans)