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
    C = deque(B)
    B.append(A[N // 2])
    C.appendleft(A[N // 2])
else:
    C = A[:]

ans1 = 0
ans2 = 0
for i in range(N - 1):
    ans1 += abs(B[i] - B[i + 1])
    ans2 += abs(C[i] - C[i + 1])

print(max(ans1, ans2))
