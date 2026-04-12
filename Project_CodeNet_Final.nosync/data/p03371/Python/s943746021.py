a,b,c,x,y=map(int,input().split())
if x==y:
    ans=min(a+b,2*c)*x
else:
    if x>y:
        ans=min(a+b,2*c)*y
        ans+=min(a,2*c)*(x-y)
    else:
        ans=min(a+b,2*c)*x
        ans+=min(b,2*c)*(y-x)
print(ans)
    