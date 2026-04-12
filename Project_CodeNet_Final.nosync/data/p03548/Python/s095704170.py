x, y, z = map(int, input().split())

sums = z
cnt = -1
for i in range(1000001):
  if sums > x:
    break
  sums += y + z
  cnt += 1

print(cnt)