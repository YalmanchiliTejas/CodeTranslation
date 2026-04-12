x,y,z=map(int,input().split())
ans=int(0)
x-=z
while x>=y+z:
    ans+=1
    x-=(y+z)

print(ans)