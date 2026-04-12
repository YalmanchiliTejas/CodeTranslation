x,y,z=map(int,input().split())
ans=x//(y+z)
print(ans if ans*(y+z)+z <= x else ans-1)