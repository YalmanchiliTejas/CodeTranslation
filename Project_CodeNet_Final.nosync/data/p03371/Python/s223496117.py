a, b, c, x, y = map(int, input().split())

if a+b<=2*c:
  print(x*a+y*b)
else:
  ans = c*2*min(x, y)
  if x>=y:
    if a<=2*c:
      ans += (x-y)*a
    else:
      ans += (x-y)*2*c
  else:
    if b<=2*c:
      ans += (y-x)*b
    else:
      ans += (y-x)*2*c
  print(ans)