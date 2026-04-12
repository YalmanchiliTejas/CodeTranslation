n = int(input())
l = []
li = list(map(int,input().split()))
ans = 0
max = 0
for i in range(len(li)):
  if max <= li[i]:
    max = li[i]
  if li[i] >= max:
    ans = ans + 1
print(ans)