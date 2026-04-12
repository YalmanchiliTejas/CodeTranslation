a,b,c,x,y = map(int, input().split())
k1 = a*x+b*y
k2 = 2*c*max(x,y)
if x < y:
  k3 = 2*c*min(x,y)+b*(y-x)
else:
  k3 = 2*c*min(x,y)+a*(x-y)

print(min(k1, k2, k3))