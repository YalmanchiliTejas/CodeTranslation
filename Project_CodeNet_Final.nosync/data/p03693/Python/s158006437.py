import numpy as np
import scipy.sparse as sps
import scipy.misc as spm
import collections as col
import functools as func
import itertools as ite
import fractions as frac
import math as ma
import cmath as cma
import copy as cp
import sys
def sinput(): return sys.stdin.readline().strip()
def iinput(): return int(sinput())
def imap(): return map(int, sinput().split())
def fmap(): return map(float, sinput().split())
def iarr(n=0):
    if n: return [0 for _ in range(n)]
    else: return list(imap())
def farr(): return list(fmap())
def sarr(n=0):
    if n: return ["" for _ in range(n)]
    else: return sinput().split()
def barr(n): return [False for _ in range(n)]
sys.setrecursionlimit(10**7)
MOD = 10**9 + 7; EPS = sys.float_info.epsilon
PI = np.pi; EXP = np.e; INF = np.inf

r,g,b = sarr()
flag = int(r+g+b)%4 == 0
ans = "YES" if flag else "NO"
print(ans)
