a, b, c, x, y = map(int, input().split())
ans = a*x + b*y
if x > y :
    ans = min(ans, 2*y*c+(x-y)*a)
    ans = min(ans, 2*x*c)
else :
    ans = min(ans, 2*x*c+(y-x)*b)
    ans = min(ans, 2*y*c)
print(ans)