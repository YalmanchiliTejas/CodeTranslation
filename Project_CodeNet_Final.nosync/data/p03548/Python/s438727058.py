x,y,z = map(int,input().split())
ans = 1
while z*(ans+1) + y*ans <= x:
  ans = ans +1

print(ans-1)
