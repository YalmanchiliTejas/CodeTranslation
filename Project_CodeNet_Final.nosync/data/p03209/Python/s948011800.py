n, x = [int(i) for i in input().split()]

num_p = [0 for i in range(n+1)]

for i in range(1, n+1):
  num_p[i] = num_p[i-1] * 2 + 1

total = 1
for i in range(1, n + 1):
  total = total * 2 + 3

cnt = 0
left = 1
right = total

for i in range(n,-1, -1):
  center = (left + right) // 2
  if x == center:
    cnt += num_p[i] + 1
    break
  if x > center:
    cnt += num_p[i] + 1
    left = center + 1
    right = right - 1
  else:
    left = left + 1
    right = center -1

print(cnt)
