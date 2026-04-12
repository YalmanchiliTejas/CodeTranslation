def a(n):
    return 2 ** (n + 2) - 3

def p(n):
    return 2 ** (n + 1) - 1

def f(l, x):
    if l == 0:
        return 1
    elif x == 1:
        return 0
    elif 1 < x <= 1 + a(l-1):
        return f(l-1, x-1)
    elif x == 2 + a(l-1):
        return p(l-1) + 1
    elif 2 + a(l-1) < x <= 2 + 2 * a(l-1):
        return p(l-1) + 1 + f(l-1, x - (2 + a(l-1)))
    else:
        return 2 * p(l-1) + 1

N, X = map(int, input().split())
print(f(N, X))