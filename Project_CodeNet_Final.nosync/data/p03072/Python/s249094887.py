n = int(input())
maxHeight = 0
cnt = 0
mt = list(map(int, input().split()))
for i in range(n):
  if mt[i] >= maxHeight:
    maxHeight = mt[i]
    cnt += 1
print(cnt)
