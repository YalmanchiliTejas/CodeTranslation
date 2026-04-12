input()
ans, mx = 0, 0
for i in list(map(int, input().split())):
  if mx <= i:
    ans += 1
    mx = i
print(ans)