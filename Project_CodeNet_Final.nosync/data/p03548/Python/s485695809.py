X,Y,Z = map(int,input().split())
X -= Z*2
ans = 0
while X>=Y:
  X -= (Y+Z)
  ans += 1
print(ans)