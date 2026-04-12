a,b,c,x,y = map(int,input().split())
ans = 0
if x > y:
    a,b,x,y = b,a,y,x
if a + b >= 2 * c:
    ans1 = 2 * c * x + b * (y - x)
    ans2 = 2 * c * y
    print(min(ans1,ans2))
else:
    print(a*x + b*y)