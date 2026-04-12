a,b,c,x,y=map(int,input().split())
ans=a*x+b*y
n=max(x,y)
for i in range(1,n+1):
  ans=min(ans,2*i*c+a*max(0,x-i)+b*max(0,y-i))
print(ans)


