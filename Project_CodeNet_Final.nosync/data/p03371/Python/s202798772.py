a,b,c,x,y = map(int,input().split())
ans = 0
if 2*c<=min(a,b):
  ans = c*max(x,y)*2
elif 2*c<=max(a,b):
  if a>b and x>y:
    ans = c*x*2
  elif a<=b and x<=y:
    ans = c*y*2
  elif a>b and x<=y:
    ans = c*x*2+b*(y-x)
  elif a<=b and x>y:
    ans = c*y*2+a*(x-y)
  else:
    ans = c*y*2+a*(x-y)
elif 2*c<=a+b:
  if x>y:
    ans = c*y*2+a*(x-y)
  else:
    ans = c*x*2+b*(y-x)
else:
  ans = a*x+b*y
print(ans)