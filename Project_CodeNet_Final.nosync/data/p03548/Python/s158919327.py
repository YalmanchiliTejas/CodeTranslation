x,y,z=map(int,input().split())
n=x//y+1
ans=0
for i in range(1,n+1):
    if i*y+(i+1)*z<=x:
        ans=i
print(ans)