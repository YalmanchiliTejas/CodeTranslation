n = int(input())
h = list(map(int, input().split()))

cnt = 1
hmax = h[0]

for i in range(1, n):
  if h[i] >= hmax:
    cnt += 1
    hmax = h[i]

print(cnt)