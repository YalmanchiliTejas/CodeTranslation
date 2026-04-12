import math, string, fractions, heapq, re, array, bisect, sys, random, time, copy
import itertools as it
import collections as cl
import functools as ft


def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()

n, k = LI()

counts = 0
for b in range(1, n+1):
    p, r = divmod(n, b)
    counts += max(0, p*(b-k)) + max(0, r-k+1)
    if k == 0:
        counts -= 1

    #print("mid: ", counts)

print(counts)