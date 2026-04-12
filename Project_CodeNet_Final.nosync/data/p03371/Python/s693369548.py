a,b,c,x,y=map(int,input().split())

mincost=min(a+b,2*c)
ans=0
while (x>0 and y>0):
    ans+=mincost
    x-=1
    y-=1

ans+=min(a,2*c)*x+min(b,2*c)*y
print(ans)
    
