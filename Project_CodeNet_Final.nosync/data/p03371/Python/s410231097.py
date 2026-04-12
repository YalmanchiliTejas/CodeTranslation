a, b, c, x, y=map(int, input().split())
p=0
if a+b > 2*c:
  p+=min(x, y)*2*c
  if x>y:
    if a>2*c:
      p+=(x-y)*2*c
    else:
      p+=(x-y)*a
  else:
    if b>2*c:
      p+=(y-x)*2*c
    else:
      p+=(y-x)*b
else:
  p+=x*a+y*b
print(p)