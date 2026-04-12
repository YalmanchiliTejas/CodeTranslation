n = int(input())
heights = list(map(int, input().split()))
res = 0
left_max = 0
for i in range(n):
  h = heights[i]
  if h >= left_max:
    res += 1
    left_max = h
print(res)