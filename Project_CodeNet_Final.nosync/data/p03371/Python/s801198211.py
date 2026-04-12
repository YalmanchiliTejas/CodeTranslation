a,b,c,x,y=list(map(int,input().split()))
ans = a*x+b*y
c = c * 2

for i in range(1,max(x,y)+1):
  if x-i < 0:
    ans1 = b*(y-i)+c*i
  elif y-i < 0:
    ans1 = a*(x-i)+c*i
  else:
    ans1 = a*(x-i)+b*(y-i)+c*i
  ans = min(ans,ans1)
print(ans)