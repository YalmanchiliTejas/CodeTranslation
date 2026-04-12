a, b, c, x, y = map(int, input().split())
a_yen = 0
b_yen = 0
c_yen = 0
if a + b <= 2*c:
    a_yen = a*x
    b_yen = b*y
    print(a_yen + b_yen)

elif a + b > 2*c:
    c_yen = 2*c*min(x, y)

    if min(x, y) == x and b <= 2*c:
        b_yen = b*(y-x)
    elif min(x, y) == x and b > 2*c:
        c_yen += 2*c*(y-x)

    elif min(x, y) == y and a <= 2*c:
        a_yen = a*(x-y)
    elif min(x, y) == y and a > 2*c:
        c_yen += 2*c*(x-y)

    print(a_yen + b_yen + c_yen)