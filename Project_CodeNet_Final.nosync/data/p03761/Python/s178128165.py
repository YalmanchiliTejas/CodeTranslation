# -*- coding: utf-8 -*-
import sys
from collections import deque, defaultdict
from math import sqrt, factorial, gcd
# def input(): return sys.stdin.readline()[:-1] # warning not \n
# def input(): return sys.stdin.buffer.readline().strip() # warning bytes
# def input(): return sys.stdin.buffer.readline().decode('utf-8')


def solve():
    n = int(input())
    d = defaultdict(int)
    s = input()
    for e in s:
        d[e] += 1
    for _ in range(n-1):
        c = defaultdict(int)
        s = input()
        for e in s:
            c[e] += 1
        for k in d:
            d[k] = min(d[k], c[k])
    a = []
    for k in d:
        if d[k]:
            a.append(k * d[k])
    a.sort()
    print(''.join(a))
    
    

        
    
t = 1
# t = int(input())
for case in range(1,t+1):
    ans = solve()


"""

7
3 1
4 1
5 9
2 6
5 3
5 8
9 7 5

"""
