a,b,c,x,y = map(int,input().split())

ans = a * x + b * y

if x < y:
    e = c * 2 * x
    f = b * (y-x)
    ans = min(ans, f+e)
    g = c * 2 * y
    ans = min(ans,g)
else:
    e = c * 2 * y
    f = a * (x-y)
    ans = min(ans, f+e)
    g = c * 2 * x
    ans = min(ans,g)
print(ans)
