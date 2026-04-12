x,y,z=map(int,input().split())
ans=1
while True:
  if ans*(y+z)+z>x:
    print(ans-1)
    exit()
  ans+=1