n = int(input())
lst = list(map(int, input().split()))
maxheight = 0
cnt = 0
for i in range(n):
  if lst[i] >= maxheight:
    maxheight = lst[i]
    cnt += 1
print(cnt)