n = int(input())
h = list(map(int, input().split()))

cnt = 0
maxh = 0
for i in range(0, n):
  if h[i] >= maxh:
    cnt += 1
    maxh = h[i]

print(cnt)