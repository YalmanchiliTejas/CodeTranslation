a,b,c,x,y=map(int,input().split())
ans=a*x+b*y
m=min(x,y)
ans=min(ans,c*m*2+a*(x-m)+b*(y-m))
m=max(x,y)
ans=min(ans,c*m*2+max(a*(x-m),0)+max(b*(y-m),0))
print(ans)