a, b, c, x, y = map(int,input().split())

if x==y:
    ans = min(x*a+y*b, 2*x*c)
elif x>y:
    ans = min(x*a+y*b, 2*x*c, (x-y)*a+2*y*c)
else:
    ans = min(x*a+y*b, 2*y*c, (y-x)*b+2*x*c)

print(ans)