a, b, c, x, y = map(int, input().split())

print(min(
    a*x + b*y,
    2*c*min(x, y) + max(a*(x-y), b*(y-x)),
    2*c*max(x, y)
    ))