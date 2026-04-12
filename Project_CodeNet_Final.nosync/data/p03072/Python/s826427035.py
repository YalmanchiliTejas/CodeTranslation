n = int(input())
li = list(map(int, input().split()))
ans = 0
tmp = 0
for i in range(n):
  if tmp <= li[i]:
    ans += 1
    tmp = li[i]

print(ans) 
