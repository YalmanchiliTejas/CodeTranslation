from functools import lru_cache as cache

@cache(maxsize=None)
def t(n):
    return 1 if n == 0 else t(n - 1) * 2 + 3

@cache(maxsize=None)
def p(n):
    return 1 if n == 0 else p(n - 1) * 2 + 1

f = lambda n, x: (0 if x <= 0 else 1) if n == 0 else f(n - 1, x - 1) if x <= 1 + t(n - 1) else p(n - 1) + 1 + f(n - 1, x - 2 - t(n - 1))

print(f(*map(int, input().split())))
