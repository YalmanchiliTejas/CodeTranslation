a, b, c, x, y = map(int, input().split())
z = min(x, y)
ans = min(a*x+b*y, a*(x-z)+b*(y-z)+2*c*z, 2*c*max(x, y))
print(ans)