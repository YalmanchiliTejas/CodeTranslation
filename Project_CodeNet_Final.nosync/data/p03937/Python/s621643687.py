# -*- coding: utf-8 -*-
import sys
from collections import deque, defaultdict
from math import sqrt, factorial, gcd
# def input(): return sys.stdin.readline()[:-1] # warning not \n
# def input(): return sys.stdin.buffer.readline().strip() # warning bytes
# def input(): return sys.stdin.buffer.readline().decode('utf-8')


def solve():
    n, w = [int(x) for x in input().split()]
    j = 0
    ok = 1
    for i in range(n):
        r = [x for x in input()]
        while r[j] == '#' and j+1 < w and r[j+1] == '#':
            r[j] = '.'
            j += 1
        if r[j] == '.' or r.count('#') != 1:
            ok = 0


    if ok:
        print("Possible")
    else:
        print("Impossible")

    




        
    

    
    

t = 1
# t = int(input())
for case in range(1,t+1):
    ans = solve()


"""

2 2 2 2 2

"""
