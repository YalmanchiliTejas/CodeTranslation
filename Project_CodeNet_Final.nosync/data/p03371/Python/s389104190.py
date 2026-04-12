a,b,c,x,y=map(int,input().split())
ans=a*x+b*y
if x>y:
    p=2*y*c+(x-y)*min(a,2*c)
    ans=min(ans,p)
if x<=y:
    p=2*x*c+(y-x)*min(b,2*c)
    ans=min(ans,p)
print(ans)
