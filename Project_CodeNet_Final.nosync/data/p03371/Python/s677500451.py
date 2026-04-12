a,b,c,x,y=map(int,input().split())
ans=1e10
for i in range(0,2*max(x,y)+1,2):
  d=c*i+max(0,x-i//2)*a+max(0,y-i//2)*b
  ans=min(d,ans)
print(ans)
  