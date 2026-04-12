x,y,z=map(int,input().split())
ans=0
while x >= y + 2*z:
  ans += 1
  x -= y + z
print(ans)