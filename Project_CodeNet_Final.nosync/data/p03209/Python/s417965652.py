import sys
from functools import lru_cache


@lru_cache(maxsize=None)
def alg_memoization_recursion(lv, n, m):
    if lv == 0:
        if m <= 0:
            return 0
        else:
            return 1
    else:
        if (n + 1) // 2 == m:
            return alg_memoization_recursion(lv - 1, n // 2 - 1, m - 1) + 1
        elif (n + 1) // 2 > m:
            return alg_memoization_recursion(lv - 1, n // 2 - 1, m - 1)
        elif n == m:
            return alg_memoization_recursion(lv - 1, n // 2 - 1, n // 2 - 1) + alg_memoization_recursion(lv - 1, n // 2 - 1, m - (n // 2) - 1) + 1
        else:
            return alg_memoization_recursion(lv - 1, n // 2 - 1, n // 2 - 1) + alg_memoization_recursion(lv - 1, n // 2 - 1, m - (n // 2) - 1) + 1


def solve():
    input = sys.stdin.readline
    mod = 10 ** 9 + 7
    n, x = list(map(int, input().rstrip('\n').split()))
    t = 1
    for i in range(1, n + 1):
        t = 1 + t + 1 + t + 1
    print(alg_memoization_recursion(n, t, x))


if __name__ == '__main__':
    solve()
