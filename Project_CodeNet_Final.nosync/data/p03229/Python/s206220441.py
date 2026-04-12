# coding:utf-8

import sys
from collections import Counter, deque

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def S(): return input()


N = I()
A = [I() for _ in range(N)]

A.sort()
B = deque()

state = 1
for i in range(N // 2):
    if state:
        B.append(A[i])
        B.appendleft(A[-(i + 1)])
    else:
        B.append(A[-(i + 1)])
        B.appendleft(A[i])
    state ^= 1
if N % 2:
    median = A[N // 2]
    if abs(B[0] - median) < abs(B[-1] - median):
        B.append(median)
    else:
        B.appendleft(median)

ans = 0
for i in range(N - 1):
    ans += abs(B[i] - B[i + 1])
print(ans)
