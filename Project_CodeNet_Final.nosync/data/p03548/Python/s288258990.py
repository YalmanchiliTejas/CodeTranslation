x,y,z = map(int, input().split())

ans = 0
t = z + y + z
while t <= x:
  ans += 1
  t += y
  t += z
print(ans)