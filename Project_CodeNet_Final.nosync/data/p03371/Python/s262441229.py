import sys
input = sys.stdin.readline

a, b, c, x, y = map(int, input().split())
c *= 2
if a+b < c:
    ans = a*x + b*y
else:
    m = min(x, y)
    ans = c*m
    if x != m:
        if a > c:
            ans += c*(x-m)
        else:
            ans += a*(x-m)
    else:
        if b > c:
            ans += c*(y-m)
        else:
            ans += b*(y-m)
print(ans)