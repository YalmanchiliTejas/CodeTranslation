import sys, io, os, re
from bisect import bisect, bisect_left, bisect_right, insort, insort_left, insort_right
from pprint import pprint
from math import sin, cos, pi, radians, sqrt, floor, ceil
from copy import copy, deepcopy
from collections import deque, defaultdict
from fractions import gcd
from functools import reduce
from itertools import groupby, combinations
from heapq import heapify, heappush, heappop

# sys.setrecursionlimit(5000)

n1 = lambda: int(sys.stdin.readline().strip())
nn = lambda: list(map(int, sys.stdin.readline().strip().split()))
f1 = lambda: float(sys.stdin.readline().strip())
fn = lambda: list(map(float, sys.stdin.readline().strip().split()))
s1 = lambda: sys.stdin.readline().strip()
sn = lambda: list(sys.stdin.readline().strip().split())
nl = lambda n: [n1() for _ in range(n)]
fl = lambda n: [f1() for _ in range(n)]
sl = lambda n: [s1() for _ in range(n)]
nm = lambda n: [nn() for _ in range(n)]
fm = lambda n: [fn() for _ in range(n)]
sm = lambda n: [sn() for _ in range(n)]

def array1(n, d=0): return [d] * n
def array2(n, m, d=0): return [[d] * m for x in range(n)]
def array3(n, m, l, d=0): return [[[d] * l for y in xrange(m)] for x in xrange(n)]
def linc(A, d=1): return list(map(lambda x: x + d, A))
def ldec(A, d=1): return list(map(lambda x: x - d, A))

N, X, M = nn()

dic = dict()

ans = 0
cyc = 0
A = X
for i in range(N):
    if i != 0 and A in dic:
        cyc = i - dic[A][0]
        cyci = dic[A][0]
        r = ans - dic[A][1]
        t = dic[A][1]
        break

    dic[A] = (i, ans)
    ans += A
    A = A**2 % M

if cyc == 0:
    print(ans)
    exit(0)

#print(N//cyc)
ans = t + r * ((N-cyci)//cyc)

for i in range((N-cyci) % cyc):
    ans += A
    A = A**2 % M

print(ans)