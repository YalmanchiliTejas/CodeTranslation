a,b,c,x,y = map(int,input().split())
ans = 0
ans2 = 10**10
if (a+b) / 2 > c:
    x2 = x - min(x,y)
    y2 = y - min(x,y)
    ans += 2 * min(x,y) * c
    ans2 = 2 * max(x,y) * c
else:
    x2 = x
    y2 = y
ans += a*x2 + b*y2

print(min(ans,ans2))