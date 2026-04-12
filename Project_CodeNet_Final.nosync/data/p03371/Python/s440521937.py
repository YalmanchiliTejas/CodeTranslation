import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()

a,b,c,x,y = na()
tot = c*2
ans = 0
if a+b <= tot:
    ans = a*x + b*y
else:
    if a > tot and b > tot:
        mi = min(x,y)
        ans = mi*2*c + (max(x,y) - mi)*2*c
    elif a > tot and b <= tot:
        mi = min(x,y)
        if mi == x:
            ans = mi*2*c + (max(x,y) - mi)*b
        else:
            ans = mi*2*c + (max(x,y) - mi)*2*c
    elif a <= tot and b > tot:
        mi = min(x,y)
        if mi == x:
            ans = mi*2*c + (max(x,y) - mi)*2*c
        else:
            ans = mi*2*c + (max(x,y) - mi)*a
    else:
        mi = min(x,y)
        if mi == x:
            ans = mi*2*c + (max(x,y) - mi)*b
        else:
            ans = mi*2*c + (max(x,y) - mi)*a
print(ans)
