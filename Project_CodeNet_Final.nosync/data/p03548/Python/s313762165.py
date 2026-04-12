X, Y, Z = [int(xyz) for xyz in input().split()]
ans = 0
X -= Z
while X >= Y+Z:
  X -= Y+Z
  ans += 1
print(ans)