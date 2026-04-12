a, b, c, x, y = map(int, input().split())

z = min(x, y)
if x > y:
    p = 2*c*z + a*(x-z)
else:
    p = 2*c*z + b*(y-z)

q = a*x + b*y
r = 2*c * max(x, y)

print(min(p, q, r))
