from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(10 ** 7)

a,b,c,x,y = map(int,stdin.readline().rstrip().split())
mi = 10**10

mi = min(mi,max(x,y)*2*c)
mi = min(mi,a*x+b*y)

if x >= y:
    mi = min(mi,y*2*c+(x-y)*a)
else:
    mi = min(mi,x*2*c+(y-x)*b)

print(mi)