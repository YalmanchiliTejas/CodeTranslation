# -*- coding: utf-8 -*-
import sys
from collections import deque, defaultdict
from math import sqrt, factorial
# def input(): return sys.stdin.readline()[:-1] # warning not \n
# def input(): return sys.stdin.buffer.readline().strip() # warning bytes
# def input(): return sys.stdin.buffer.readline().decode('utf-8')


def solve():
    a, b, c, x, y = [int(x) for x in input().split()]
    c *= 2
    ans = 0
    if c < a + b:
        z = min(x, y)
        ans += c * z
        x -= z
        y -= z
    if x:
        if c * x < a * x:
            ans += c * x
        else:
            ans += a * x
    if y:
        if c * y < b * y:
            ans += c * y
        else:
            ans += b * y
    print(ans)

t = 1
# t = int(input())
for case in range(1,t+1):
    ans = solve()


"""

a aa c ca c a b a ab a b c

"""
