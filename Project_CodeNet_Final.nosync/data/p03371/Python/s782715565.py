a, b, c, x, y = map(int, input().split())

# ABを買わない、AorBを買わない、AandBを買わない
if x >= y:
    print(min(x*a + y*b, 2*y*c + (x - y)*a, 2*x*c))
else:
    print(min(x*a + y*b, 2*x*c + (y - x)*b, 2*y*c))