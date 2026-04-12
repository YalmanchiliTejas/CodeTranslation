import sys
from itertools import permutations

sys.setrecursionlimit(10 ** 7)
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n, m = map(int, input().split())
    edge = set()
    for _ in range(m):
        a, b = map(int, input().split())
        edge.add((a - 1, b - 1))
        edge.add((b - 1, a - 1))

    res = 0
    for pattern in permutations(range(n)):
        if pattern[0] == 0:
            for i in range(1, n):
                prev = pattern[i - 1]
                now = pattern[i]
                if (prev, now) not in edge:
                    break
            else:
                res += 1
    print(res)


if __name__ == '__main__':
    resolve()
