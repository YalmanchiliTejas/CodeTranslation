a,b,c,x,y=map(int,input().split())
ans=float('inf')
for i in range(max(x,y)+1):
  ans=min(ans,2*i*c+a*max(0,x-i)+b*max(0,y-i))
print(ans)