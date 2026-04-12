def l(n):
    return 2 ** (n+2) - 3


def p(n):
    return 2 ** (n+1) - 1


def countp(n, x):
    if n == 0:
        return 1
    if x == 1:
        return 0
    if 1 < x <= 1 + l(n-1):
        return countp(n-1, x-1)
    if x == 1 + l(n-1) + 1:
        return p(n-1) + 1
    if 1 + l(n-1) + 1 < x <= 1 + l(n-1) + 1 + l(n-1):
        return p(n-1) + 1 + countp(n-1, x-1-l(n-1)-1)
    return p(n-1) + 1 + p(n-1)


N, X = map(int, input().split())
print(countp(N, X))
