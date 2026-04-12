#codng utf-8
a,b,c,x,y=map(int,input().split())
ans=0

if x==y:
    ans+=min(a+b,2*c)*x
else:
    if x<y:
        ans+=min(a+b,2*c)*x
        ans+=min(b,2*c)*abs(y-x)
    else:
        ans+=min(a+b,2*c)*y
        ans+=min(a,2*c)*abs(y-x)

print(ans)