n = int(input())
h = list(map(int, str(input()).split()))
max_height = 0
count = 1
for i in range(1, n):
  max_height = max(max_height, h[i-1])
  count += (h[i] >= max_height)
print(count)