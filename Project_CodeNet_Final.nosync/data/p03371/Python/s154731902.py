a,b,c,x,y=map(int,input().split())
ans=0
ans1=0

e=max(x,y)
ans1=e*(2*c)
if 2*c<a+b:
    d=min(x,y)
    ans+=c*(2*d)
    x-=d
    y-=d
else:
    ans=a*x+b*y
    x-=x
    y-=y
ans+=x*a
ans+=y*b
print(min(ans,ans1))