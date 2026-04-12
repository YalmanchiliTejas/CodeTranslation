N, X = map(int, input().split())


def a(N):
    return 2 ** (N + 2) - 3


def p(N):
    return 2 ** (N + 1) - 1


def f(N, X):
    if N == 0:
        return 1 if X > 0 else 0

    if X == 1:
        return 0
    elif X <= 1 + a(N - 1):
        return f(N - 1, X - 1)
    else:
        return p(N - 1) + 1 + f(N - 1, X - 2 - a(N - 1))


print(f(N, X))
