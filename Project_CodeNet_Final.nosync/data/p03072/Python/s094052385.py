N = int(input())
list = input().split()
ans = 0
maxHeight = -1
for i in range(N):
  if int(list[i]) >= maxHeight:
    ans += 1
    maxHeight = int(list[i])
print(ans)