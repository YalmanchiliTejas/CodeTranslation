def resolve():
    a, b, c, x, y = map(int, input().split())
    p1 = x*a + y*b
    minp = min(x, y)
    if x >= y:
        p2 = minp*2*c + (max(x, y)-minp)*a

    else:
        p2 = minp * 2 * c + (max(x, y) - minp) * b
    p3 = max(x, y) * 2 * c
    print(min(p1, p2, p3))

resolve()