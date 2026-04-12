x, y, z = map(int, input().split())

ans = 0
for i in range(100000):
  if (y * i) + (z * (i+1)) <= x:
    ans = i
  else:
    break
print(ans)
    