a,b,c,x,y=map(int,input().split())
ans=0
if a+b<2*c:
   ans+=a*x+b*y
else:
    if x>y:
        if 2*c>a:
            ans+=c*2*y+a*(x-y)
        else:
            ans+=c*2*x
    else:
        if 2*c>b:
            ans+=c*2*x+b*(y-x)
        else:
            ans+=c*2*y
print(ans)
