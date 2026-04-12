from functools import lru_cache
n, x = map(int, input().split())

@lru_cache(None)
def d(k):
    if k == 0:
        return 1
    return 2 * d(k-1) + 3

@lru_cache(None)
def f(i, h):
    if h == 0:
        return i
    rv = 0
    if i >= 1:
        rv += f(min(i-1, d(h-1)), h-1)
    if i >= d(h-1) + 2:
        rv += 1 + f(min(i - d(h-1) - 2, d(h-1)), h-1)
    return rv

print(f(x, n))
