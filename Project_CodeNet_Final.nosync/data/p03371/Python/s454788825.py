a, b, c, x, y = map(int, input().split())

cost_a = a * x
w_x = x

cost_b = b * y
w_y = y

if c * 2 < a + b:
    w_c = min(x, y) * 2
    w_x = x - min(x, y)
    w_y = y - min(x, y)

    if w_x > 0:
        if a > c * 2:
            w_c += w_x * 2
            w_x = 0

    if w_y > 0:
        if b > c * 2:
            w_c += w_y * 2
            w_y = 0

    print(w_x * a + w_y * b + w_c * c)
else:
    print(cost_a + cost_b)



