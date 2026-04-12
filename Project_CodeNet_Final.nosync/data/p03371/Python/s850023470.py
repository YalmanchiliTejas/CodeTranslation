a, b, c, x, y = map(int, input().split())
ans = 10**10
ans = min(ans, a*x + b*y)
ans = min(ans, c*2*x + b*max(0, y - x))
ans = min(ans, c*2*y + a*max(0, x - y))
print(ans)