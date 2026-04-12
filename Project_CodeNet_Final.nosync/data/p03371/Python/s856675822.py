#C
import sys
a, b, c, x, y = map(int,input().split())
ans = 0
if a + b <= 2*c:
    print(a*x + b*y)
else:
    ans += min(x,y) * 2*c
    r = max(x,y) - min(x,y)
    if max(x,y) == x:
        if a <= 2*c:
            ans += a*r
        else:
            ans += 2*c*r
    else:
        if b <= 2*c:
            ans += b*r
        else:
            ans += 2*c*r
    print(ans)