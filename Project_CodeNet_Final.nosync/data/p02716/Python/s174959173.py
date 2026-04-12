import os

import itertools
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7


# MOD = 998244353


def test(N, A):
    ret = -INF
    for choices in itertools.combinations(range(N), N // 2):
        ok = True
        for i, j in zip(choices, choices[1:]):
            if abs(i - j) == 1:
                ok = False
                break
        if ok:
            s = 0
            for i in choices:
                s += A[i]
            ret = max(ret, s)
    print(ret)


N = int(sys.stdin.buffer.readline())
A = list(map(int, sys.stdin.buffer.readline().split()))
N = len(A)

cnt = 2 if N % 2 == 1 else 1
# dp[i][j]: iまでみて、j個とばしたときの総和の最大値
dp = [[-INF] * (cnt + 1) for _ in range(N + 2)]
for i in range(cnt + 1):
    dp[i][i] = 0
for i in range(N):
    for j in range(cnt + 1):
        for k in range(cnt + 1):
            if i + 2 + k < len(dp) and j + k < len(dp[0]):
                dp[i + 2 + k][j + k] = max(dp[i + 2 + k][j + k], dp[i][j] + A[i])
print(dp[-1][-1])

# test(N, A)
