import os
import os
import sys
from collections import deque

import numpy as np

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

N = int(sys.stdin.readline())
A = [int(sys.stdin.readline()) for _ in range(N)]


def solve(A):
    if N % 2 == 0:
        ans = [-1] * N
        for i, a in enumerate(A[:N // 2]):
            ans[i * 2 + 1] = a
        for i, a in enumerate(A[N // 2:]):
            ans[i * 2] = a
    else:
        ans = deque()
        que = deque(A)
        while len(que) > 1:
            ans.append(que.popleft())
            ans.append(que.pop())
        ans.appendleft(que.pop())
        ans = list(ans)
    return np.abs(np.diff(ans)).sum()


A.sort()
a = solve(A)
A.reverse()
b = solve(A)
print(max(a, b))

#
# def solve():
#     ans = []
#     for li in itertools.permutations(A):
#         ans.append((np.abs(np.diff(li)).sum(), li))
#     ans.sort()
#
#     print(*ans, sep='\n')
#
#
# solve()
