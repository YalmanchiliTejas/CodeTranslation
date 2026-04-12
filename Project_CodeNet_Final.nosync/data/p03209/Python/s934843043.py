import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7
# MOD = 998244353

N, X = list(map(int, sys.stdin.buffer.readline().split()))

sizes = [1]
for _ in range(N):
    sizes.append(sizes[-1] * 2 + 3)
patties = [1]
for _ in range(N):
    patties.append(patties[-1] * 2 + 1)


def solve(n, x):
    if sizes[n] <= x:
        return patties[n]
    if x <= 0:
        return 0
    ret = 0
    ret += solve(n - 1, x - 1)
    ret += 1 if x > sizes[n] // 2 else 0
    ret += solve(n - 1, x - sizes[n] // 2 - 1)
    return ret


ans = solve(N, X)
print(ans)
