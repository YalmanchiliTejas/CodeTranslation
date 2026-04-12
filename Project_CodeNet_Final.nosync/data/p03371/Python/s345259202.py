a, b, c, x, y = map(int, input().split())


if x >= y:
    tmp1 = y*2*c + (x-y)*a
    tmp2 = c*x*2
    tmp3 = a*x + b*y
    print(min(tmp1, tmp2, tmp3))
else:
    tmp1 = x * 2 * c + (y-x) * b
    tmp2 = c * y * 2
    tmp3 = a * x + b * y
    print(min(tmp1, tmp2, tmp3))
