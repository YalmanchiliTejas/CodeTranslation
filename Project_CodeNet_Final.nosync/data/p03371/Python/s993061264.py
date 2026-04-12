a, b, c, x, y = map(int, input().split())

ans = 0

if (a+b)/2 >= c:
    ans = c* 2 * min(x,y)
else:
    ans += (a+b)*min(x,y)
if x >= y:
    ans += min(a*(x-y), 2*c*(x-y))
else:
    ans += min(b*(y-x), 2*c*(y-x))

print(ans)