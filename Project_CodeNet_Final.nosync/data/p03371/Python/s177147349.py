a, b, c, x, y=map(int, input().split())
ans = float("inf")
for i in range(max(x,y)+1):
  pa=max(0,x-i)
  pb=max(0,y-i)
  temp = c*2*i+a*pa+b*pb
  ans=min(ans,temp)
print(ans)