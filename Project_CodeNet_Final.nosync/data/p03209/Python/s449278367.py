import sys
from functools import lru_cache


@lru_cache(maxsize=None)
def func(num, pos):
    if num == 1:
        return 1
    elif pos == 1:
        return 0
    elif 1 < pos < (num + 2 - 1) // 2:
        return func((num - 3) // 2, pos - 1)
    elif pos == (num + 2 - 1) // 2:
        return func((num - 3) // 2, (num - 3) // 2) + 1
    elif (num + 2 - 1) // 2 < pos < num:
        return func((num - 3) // 2, (num - 3) // 2) + func((num - 3) // 2, pos - (num - 3) // 2 - 2) + 1
    elif pos == num:
        return func((num - 3) // 2, (num - 3) // 2) * 2 + 1


def solve():
    input = sys.stdin.readline
    mod = 10 ** 9 + 7
    n, x = list(map(int, input().rstrip('\n').split()))
    t = 1
    for i in range(n):
        t = t * 2 + 3
    print(func(t, x))


if __name__ == '__main__':
    solve()
