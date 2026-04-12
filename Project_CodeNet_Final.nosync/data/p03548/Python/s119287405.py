x, y, z = map(int, input().split())
cnt = 0
x -= z
while x > 0:
  if x-y-z >= 0:
    x -= y+z
    cnt += 1
  else:
    break
print(cnt)