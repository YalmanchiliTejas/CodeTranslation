a,b,c,x,y=map(int,input().split())
ans=a*x+b*y
for i in range(1,max(x,y)+1):
  ab=i*2
  abc=ab*c+a*max(0,x-i)+b*max(0,y-i)
  ans = min(ans,abc)
print(ans)
