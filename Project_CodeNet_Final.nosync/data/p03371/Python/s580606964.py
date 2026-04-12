a, b, c, x, y = list(map(int, input().split()))
ab = min([a+b, 2*c])
if(x < y):
    a1 = ab * x + b * (y-x)
    a2 = ab * y
else:
    a1 = ab * y + a * (x-y)
    a2 = ab * x
print(min([a1, a2]))