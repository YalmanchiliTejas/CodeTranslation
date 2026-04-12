import sys
import math
import itertools
import bisect
from copy import copy
from collections import deque,Counter
from decimal import Decimal
def s(): return input()
def k(): return int(input())
def S(): return input().split()
def I(): return map(int,input().split())
def X(): return list(input())
def L(): return list(input().split())
def l(): return list(map(int,input().split()))
def lcm(a,b): return a*b//math.gcd(a,b)
sys.setrecursionlimit(10 ** 9)
mod = 10**9+7
count = 0
ans = 0
inf = float("inf")

h,w = I()
board = [X() for _ in range(h)]
num = []
nn = []

for i in range(h):
    if "#" not in board[i]:
        num.append(i)

for i in num:
    a = i - count
    del board[a]
    count += 1

for i in range(w):
    nn.append(i)
    for j in range(len(board)):
        if board[j][i] == "#":
            nn.remove(i)
            break

for i in range(len(board)):
    cnt = 0
    for j in nn:
        b = j-cnt
        del board[i][b]
        cnt += 1

for i in range(len(board)):
    print("".join(board[i]))
