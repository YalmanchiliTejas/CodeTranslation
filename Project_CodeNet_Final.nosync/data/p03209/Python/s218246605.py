from functools import lru_cache as cache

@cache(maxsize=None)
def t(n):
    return 1 if n == 0 else t(n - 1) * 2 + 3

@cache(maxsize=None)
def p(n):
    return 1 if n == 0 else p(n - 1) * 2 + 1

N, X = map(int, input().split())

def f(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= 1 + t(N - 1):
        return f(N - 1, X - 1)
    else:
        return p(N - 1) + 1 + f(N - 1, X - 2 - t(N - 1))

print(f(N, X))
