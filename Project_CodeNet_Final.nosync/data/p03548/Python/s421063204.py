x,y,z=map(int,input().split())
ans = 0
x -= z
while x >= y+z:
  x -= (y+z)
  ans += 1
print(ans)