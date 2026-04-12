import sys
from itertools import permutations

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n, m = map(int, input().split())
    tree = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        tree[a - 1].append(b - 1)
        tree[b - 1].append(a - 1)

    res = 0
    for pattern in permutations(range(n)):
        if pattern[0] == 0:
            for i in range(n - 1):
                if pattern[i + 1] not in tree[pattern[i]]:
                    break
            else:
                res += 1
    print(res)



if __name__ == '__main__':
    resolve()
