x,y,z=map(int,input().split())
ans=int(x/(y+z))
if x-ans*(y+z)>=z:
    print(ans)
else:
    print(ans-1)