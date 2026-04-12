import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy,copy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

def main():
  h, w = MAP()
  a = [list(input()) for _ in range(h)]
  g = []
  r = []
  for i in range(h):
    for j in range(w):
      if a[i][j] == "#":
        g.append(i)
        r.append(j)
  g = set(g)
  r = set(r)
  #print(g)
  #print(r)
  for i in g:
    for j in r:
      print(a[i][j], end='')
    print()

if  __name__=='__main__':
    main()
