a,b,c,x,y=map(int,input().split())
ans1 = a*x+b*y
if x<y:
  ans2 = x*2*c+b*(y-x)
else:
  ans2 = y*2*c+a*(x-y)
ans3 = max(x,y)*2*c
print(min(ans1,ans2,ans3))