# encoding: utf-8
import math, sys

N = int(input())
A = [int(input()) for i in range(N)]

A_up = sorted(A)
A_down = list(A_up[::-1])

# magic-hand-like order
# 1 2 3
# |X X  4 <- this node is taken last
# 7 6 5

ans = 0
for i in range(N // 2):
    if i == 0:
        ans += (A_down[0] - A_up[0])
    else:
        ans += (A_down[i - 1] - A_up[i])
        ans += (A_down[i] - A_up[i - 1])

if N % 2:
    ans += max((A_down[N // 2 - 1] - A_down[N // 2], A_up[N // 2] - A_up[N // 2 - 1]))

print(ans)