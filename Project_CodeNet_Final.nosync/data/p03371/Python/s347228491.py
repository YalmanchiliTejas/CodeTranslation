import sys
import itertools
import math
from collections import deque
MAX_INT = int(10e15)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

A,B,C,X,Y = IL()

ans = 0
if C*2 < A+B:
  ans += C*2 * min(X, Y)
  num = 0
  if X < Y:
    num = (Y - X)*B
    num = min(num, (Y - X)*C*2)
  else:
    num += (X - Y)*A
    num = min(num, (X - Y)*C*2)
  ans += num
  print(ans)
else:
  print(A*X + B*Y)