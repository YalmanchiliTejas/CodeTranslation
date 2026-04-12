import sys
from collections import deque
from itertools import *


def I(): return int(sys.stdin.readline().rstrip())


def LI(): return list(map(int, sys.stdin.readline().rstrip().split()))


def S(): return sys.stdin.readline().rstrip()


def LS(): return list(sys.stdin.readline().rstrip().split())


A, B, C, X, Y = LI()
avg = (A+B)/2
ans = 0
if avg > C:
    ans += C * min(X, Y) * 2
    if X > Y:
        if A > C * 2:
            ans += C * (X - Y) * 2
        else:
            ans += A * (X - Y)
    elif X < Y:
        if B > C * 2:
            ans += C * (Y - X) * 2
        else:
            ans += B * (Y - X)
    elif X == Y:
        pass
else:
    ans = A * X + B * Y
print(ans)
