a,b,c,x,y = map(int,input().split())
ans = 0
if (a+b) >= (2*c):
  ans += 2*c*min(x,y)
  if (x > y) and (a > 2*c):
    ans += 2*c*(x-y)
  elif (x > y) and (a <= 2*c):
    ans += a*(x-y)
  elif (x < y) and (b > 2*c):
    ans += 2*c*(y-x)
  elif (x < y) and (b <= 2*c):
    ans += b*(y-x)
else:
  ans += a*x+b*y

print(ans)