a,b,c,x,y=map(int,input().split())
ans=min(x*a+y*b,2*max(x,y)*c)
if x>=y:
    ans=min(ans,2*y*c+(x-y)*a)
else:
    ans=min(ans,2*x*c+(y-x)*b)
print(ans)