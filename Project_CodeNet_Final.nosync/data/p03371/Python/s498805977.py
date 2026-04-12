if __name__ == '__main__':
    A, B, C, X, Y = map(int, input().split())

    # A, B, C, X, Y = map(int, "1500 2000 1600 3 2".split())
    # A, B, C, X, Y = map(int, "1500 2000 1900 3 2".split())
    # A, B, C, X, Y = map(int, "1500 2000 500 90000 100000".split())

    # not buy AB
    if A + B < 2 * C:
        total = A * X + B * Y
        print(total)
        exit(0)

    # buy AB
    n_c_at_least = 2 * min(X, Y)

    X, Y = X - n_c_at_least // 2, Y - n_c_at_least // 2
    total = C * n_c_at_least

    if X > Y:
        total += min(A, 2 * C) * (X - Y)
    else:
        total += min(B, 2 * C) * (Y - X)

    print(total)
