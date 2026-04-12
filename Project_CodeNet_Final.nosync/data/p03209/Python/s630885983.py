n, x = map(int, input().split())


def p(level):
    if level == 0:
        return 1
    return 2*p(level-1)+1


def a(level):
    if level == 0:
        return 1
    return 2*a(level-1)+3


def f(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= 1 + a(N-1):
        return f(N-1, X-1)
    else:
        return p(N-1) + 1 + f(N-1, X-2-a(N-1))



print(f(n, x))