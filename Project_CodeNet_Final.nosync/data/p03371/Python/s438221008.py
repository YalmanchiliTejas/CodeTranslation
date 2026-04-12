a, b, c, x, y = map(int, input().split())

ans = a*x + b*y
ans = min(ans, 2*c*max(x, y))
if x < y:
    ans = min(ans, c*2*x + b*(y-x))
else:
    ans = min(ans, c*2*y + a*(x-y))
print(ans)