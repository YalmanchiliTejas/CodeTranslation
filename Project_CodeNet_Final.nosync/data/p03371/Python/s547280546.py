def abc095c_half_and_half():
    a, b, c, x, y = map(int, input().split())
    total = 0
    if a + b >= 2 * c:
        v = min(x, y)
        total += c * v * 2
        x -= v
        y -= v
    if a >= 2 * c:
        total += 2 * x * c
    else:
        total += x * a
    if b >= 2 * c:
        total += 2 * y * c
    else:
        total += y * b
    print(total)
abc095c_half_and_half()