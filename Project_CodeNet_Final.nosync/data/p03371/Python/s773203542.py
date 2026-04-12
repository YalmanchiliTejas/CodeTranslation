a,b,c,x,y = map(int,input().split())
ans = 10**18
for i in range(0,max(x,y)+1):
  ans = min(ans,2*c*i+a*max(0,x-i)+b*max(0,y-i))
print(ans)