a,b,c,x,y=map(int,input().split())
ans=10000000000
for i in range(0,(max(x,y)+1)):
  k=c*2*i+a*max(0,(x-i))+max(0,b*(y-i))
  ans=min(ans,k)
print(ans)