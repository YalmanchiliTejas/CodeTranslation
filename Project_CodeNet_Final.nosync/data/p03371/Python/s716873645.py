a,b,c,x,y=map(int,input().split())


if a+b>=2*c:
    ans=min(2*c*max(x,y), 2*c*min(x,y)+a*(x-min(x,y))+(b*(y-min(x,y))))
else:
    ans=a*x+b*y
print(ans)