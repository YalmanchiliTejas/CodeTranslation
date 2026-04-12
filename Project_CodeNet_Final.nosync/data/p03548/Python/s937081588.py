x, y, z = map(int, input().split())
n = z
cnt = 0
while n + (y + z) <= x:
  n += (y + z)
  cnt += 1
print(cnt)