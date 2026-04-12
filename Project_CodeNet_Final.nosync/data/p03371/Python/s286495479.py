a, b, c, x, y = map(int, input().split())
case1 = a * x + b * y
if x >= y:
    case2 = c * 2 * y + a * (x - y)
    case3 = c * 2 * x
else:
    case2 = c * 2 * x + b * (y - x)
    case3 = c * 2 * y
print(min(case1, case2, case3))