a,b,c,x,y = map(int, input().split())
if x<y:
  x,y = y,x
  a,b = b,a
d = min(2*c, a+b)
a = min(a, 2*c)
print(y*d+(x-y)*a)
