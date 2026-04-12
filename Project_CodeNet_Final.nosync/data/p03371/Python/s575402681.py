a,b,c,x,y = map(int, input().split())

ans = 0
if a > 2*c and x > 0:
  ans += x*2*c
  y -= x
  x = 0
if b > 2*c and y > 0:
  ans += y*2*c
  x -= y
  y = 0
if a+b >= 2*c and x > 0 and y > 0:
  ans += 2*c*min(x,y)
  if x < y:
    y -= x
    x = 0
  elif y < x:
    x -= y
    y = 0
  else:
    x,y = 0,0
if x > 0: ans += x*a
if y > 0: ans += y*b
print(ans)