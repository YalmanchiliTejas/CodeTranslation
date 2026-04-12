import math
a, b, c, x, y = map(int, input().split())
n = a*x + b*y
m = c*2*max(x,y)
min_xy = min(x,y)
k = min_xy*2*c + (x-min_xy)*a + (y-min_xy)*b
print(min(n,m,k))