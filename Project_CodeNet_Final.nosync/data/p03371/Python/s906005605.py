a, b, c, x, y = [int(arg) for arg in input().split()]

default = a * x + b * y
if x < y:
    print(min(default, c*2*x+b*(y-x), c*2*y))
else:
    print(min(default, c*2*y+a*(x-y), c*2*x))
