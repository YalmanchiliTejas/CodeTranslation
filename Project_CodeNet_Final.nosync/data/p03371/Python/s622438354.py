a, b, c, x, y = map(int, input().split())

if x < y:
    print(min(2*c*y, 2*c*x+b*(y-x), a*x+b*y))
else:
    print(min(2*c*x, 2*c*y+a*(x-y), a*x+b*y))