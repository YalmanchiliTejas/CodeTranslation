a,b,c,x,y=map(int,input().split())
ans=a*x+b*y
if x==y:
    ans=min(ans,2*x*c)
elif x>y:
    ans=min(ans,a*(x-y)+2*y*c)
    ans=min(ans,2*x*c)
else:
    ans=min(ans,b*(y-x)+2*x*c)
    ans=min(ans,2*y*c)
print(ans)