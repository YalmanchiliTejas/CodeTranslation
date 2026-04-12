a,b,c,x,y=map(int,input().split())

ans=0
ans+=min(x,y)*min(a+b,2*c)
x,y=x-min(x,y),y-min(x,y)

ans+=x*min(a,2*c)
ans+=y*min(b,2*c)

print(ans)