n = int(input())
h = [int(i) for i in input().split()]
max = 0
cnt = 0
for i in range(n):
  if h[i] >= max:
    cnt += 1
  if max < h[i]:
    max = h[i]
print(cnt)