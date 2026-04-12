a, b, c, x, y = map(int, input().split())

res = (
    c * max(x, y) * 2,
    a*x + b*y,
    c*x*2 + b*max(y-x, 0),
    c*y*2 + a*max(x-y, 0)
)

print(min(res))