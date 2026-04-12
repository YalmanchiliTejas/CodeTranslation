
def resolve():
    A, B, C, X, Y = map(int, input().split())

    yen = 0
    if A - C + B - C > 0:
        yen += C * 2 * min(X, Y)

        minans = 10 ** 30
        rest = max(X, Y) - min(X, Y)
        for i in range(rest + 1):
            if X > Y:
                minans = min((C*2 * i + (rest - i) * A), minans)
            else:
                minans = min((C*2 * i + (rest - i) * B), minans)

        yen += minans

    else:
        yen = A * X + B * Y

    print(yen)


resolve()