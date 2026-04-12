a, b, c, x, y = map(int, input().split())
m = min(x, y)
M = max(x, y)
p = a * x + b * y
q = c*m*2 + a*(x-m) + b*(y-m)
r = c*M*2
print(min(p, q, r))