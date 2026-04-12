x,y,z=map(int,input().split())
ans=x//(y+z)
if x%(y+z)>=z:
    print(ans)
else:
    print(ans-1)
