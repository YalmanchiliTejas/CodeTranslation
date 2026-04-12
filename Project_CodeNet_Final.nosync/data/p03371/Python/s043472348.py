a,b,c,x,y = map(int, input().split())
xymin = min(x,y)
case1 = a*x + b*y
case2 = max(x,y)*2*c
case3 = (x-xymin)*a + (y-xymin)*b + xymin*c*2

print(min(case1,case2,case3))