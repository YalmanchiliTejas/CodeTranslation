import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

from functools import lru_cache

n, k = map(int, read().split())


@lru_cache()
def check(n, k):
    if n < 10:
        if k == 0:
            return 1
        if k == 1:
            return n
        return 0
    a, b = divmod(n, 10)
    cnt = 0
    if k >= 1:
        cnt += check(a, k - 1) * b
        cnt += check(a - 1, k - 1) * (9 - b)
    cnt += check(a, k)
    return cnt


print(check(n, k))
