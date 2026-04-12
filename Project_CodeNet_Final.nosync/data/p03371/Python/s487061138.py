a, b, c, x, y = [int(w) for w in input().split()]

if 2 * c >= a + b:
    ans = a * x + b * y
else:
    cnum = min(x, y) * 2

    less = abs(x - y)
    p = a if x > y else b
    if 2 * c < p:
        cnum += 2 * less
        less = 0

    ans = c * cnum + less * p

print(ans)
