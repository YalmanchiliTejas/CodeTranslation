x,y,z=map(int,input().split())

res=x-z
ans=0
while res>=y+z:
    res-=(y+z)
    ans+=1
print(ans)