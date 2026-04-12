A, B, C, X, Y = map(int, input().split())

res = 0

is_lower_a = True
if X > Y:
    is_lower_a = False

if A + B >= 2 * C:
    if is_lower_a:
        res += 2 * C * X
    else:
        res += 2 * C * Y
    if X != Y:
        if is_lower_a:
            if 2 * C <= B:
                res += (Y - X) * 2 * C
            else:
                res += (Y - X) * B
        else:
            if 2 * C <= A:
                res += (X - Y) * 2 * C
            else:
                res += (X - Y) * A
else:
    res += A * X
    res += B * Y
print(res)
