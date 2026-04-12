# coding: utf-8
import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

A, B, C, X, Y = lr()
if X > Y:
    A, B = B, A
    X, Y = Y, X
# X < Y の条件
AB2 = 2 * C
answer = 0
if AB2 < A + B:
    answer += AB2 * X
    Y -= X; X = 0
else:
    answer += (A + B) * X
    Y -= X; X = 0
if AB2 < B:
    answer += AB2 * Y
else:
    answer += B * Y

print(answer)
