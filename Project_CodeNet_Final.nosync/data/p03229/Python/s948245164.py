# https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_c
# WA

from collections import deque

n = int(input())
A = [int(input()) for _ in range(n)]
A.sort(reverse=True)

# edit ans
# n=9のとき
# (1) a1 > a2 < a3 > a4 < a5 > a6 < a7 > a8 < a9
# (2) a1 < a2 > a3 < a4 > a6 < a6 > a7 < a8 > a9

# (1)のとき
# (a1 - a2) + (a3 - a2) + (a3 - a4) + ...
# -> a1 1, a2 -2, a3 2, a4 -2, ..., a8 -2, a9 1
# => 2, 2, 2, 1, 1, -2, -2, -2, -2 が係数
# 
# (2)のとき
# -> a1 -1, a2 2, a3 -2, ... a8 2, a9 -1
# => 2, 2, 2, 2, -1, -1, -2, -2, -2 が係数
#
# (N)偶数のとき (N=10)
# => 2, 2, 2, 2, 1, -1, -2, -2, -2, -2

if n % 2 == 0:
    res = 0
    for i in range(n // 2 - 1):
        res += A[i] * 2
    res += A[n // 2 - 1]
    res -= A[n // 2]
    for i in range(n // 2 + 1, n):
        res -= A[i] * 2
    print(res)

else:
    # pattern 1
    res1 = 0
    for i in range(n // 2 - 1):
        res1 += A[i] * 2
    res1 += A[n // 2 - 1] + A[n // 2]
    for i in range(n // 2 + 1, n):
        res1 -= A[i] * 2

    # pattern 2
    res2 = 0
    for i in range(n // 2):
        res2 += A[i] * 2
    res2 -= (A[n // 2] + A[n // 2 + 1])
    for i in range(n // 2 + 2, n):
        res2 -= A[i] * 2
    print(max(res1, res2))