a,b,c,x,y = map(int, input().split())
ab = a*x + b*y
if min(x,y) == x:
    abc = c*x*2 + (y-x) * b
else:
    abc = c*y*2 + (x-y) * a
all_c = max(x,y) * c * 2
print(min(ab, abc, all_c))