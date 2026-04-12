import sys
from collections import defaultdict, deque
from heapq import *
sys.setrecursionlimit(200000)
input = sys.stdin.readline

N, M, = map(int, input().split())
# N = int(input())
# L = [int(v) for v in input().split()]
# L = [[int(v) for v in input().split()] for _ in range(N)]
# L = [int(input()) for _ in range(N)]
# L = [list(input().strip())  for _ in range(N)]
# S = input().strip()

m = {}
def f(n):
    if m.get(n) != None:
        return m[n]
    if n == 0:
        m[n] = (1, 1)
    else:
        b = f(n - 1)
        m[n] = (b[0] * 2 + 3, b[1] * 2 + 1)
    return m[n]

f(N)

def ff(n, t):
    if n == 0:
        return 0 if t <= 0 else 1
    elif t <= 1 + m[n - 1][0]:
        return ff(n - 1, t - 1)
    else:
        return m[n - 1][1] + 1 + ff(n - 1, t - 2 - m[n - 1][0])

print(ff(N, M))