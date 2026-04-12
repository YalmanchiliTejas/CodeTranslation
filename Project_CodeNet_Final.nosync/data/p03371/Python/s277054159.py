#!/usr/bin/env python
a, b, c, x, y = map(int, input().split())
if a + b <= 2*c:
    ans = a*x+b*y
else:
    ans = 2 * c * min(x, y)
    if x >= y:
        add = min(a*(x-y), 2 * c * (x-y))
        ans += add
    else:
        add = min(b*(y-x), 2 * c * (y-x))
        ans += add

print(ans)