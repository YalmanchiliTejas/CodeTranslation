import sys

sys.setrecursionlimit(10 ** 5 + 10)


def input(): return sys.stdin.readline().strip()


def resolve():
    a, b, c, x, y = map(int, input().split())
    ans = 10 ** 10
    yen = 0
    if a + b > c * 2:
        yen += (c * 2 * min(x, y))
        x, y = x - min(x, y), y - min(x, y)

        if x > 0:
            yen += min(x * a, x * 2 * c)
        else:
            yen += min(y * b, y * 2 * c)

    else:
        yen += a * x + b * y
    print(yen)


resolve()