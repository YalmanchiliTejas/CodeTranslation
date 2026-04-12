# coding:utf-8

import sys
import math
import time
#import numpy as np
import collections
from collections import deque
import queue
import copy

# 最大公約数
def gcd(m,n):
  x = max(m,n)
  y = min(m,n)
  if x%y == 0:
    return y
  else:
    while x%y != 0:
      z = x%y
      x = y
      y = z
    else:
      return z

# 幅優先探索(BFS)でスタート座標(x, y)からの最大距離返す
def bfs(SS, x, y, H, W):#入力(座標系(迷路), x, y, xの端, yの端)
  x_next = [0, 0, -1, 1]
  y_next = [1, -1, 0, 0]
  tempx = x
  tempy = y
  mlength = 0
  q = deque()
  xytuple = (x, y, 0)
  q.append(xytuple)


  while q:
    xytuple = q.popleft()
    SS[xytuple[0]][xytuple[1]] = "x" #探索した場所は探索できないようにする
    for i in range(4): #このforで上下左右を調べてる
      tempx = xytuple[0] + x_next[i]
      tempy = xytuple[1] + y_next[i]
      #print(tempx, tempy, xytuple[2])
      #print(S)
      if(0 <= tempx and tempx < H and 0 <= tempy and tempy < W and SS[tempx][tempy] == "."):
        temptuple = (tempx, tempy, xytuple[2]+1)
        SS[temptuple[0]][temptuple[1]] = "x" #探索した場所は探索できないようにする
        mlength = max(mlength, xytuple[2] +1)
        q.append(temptuple)
      #print(q)
  return mlength

#素因数分解
def prime_factorize(n):
  a = []
  while n % 2 == 0:
    a.append(2)
    n //= 2
  f = 3
  while f * f <= n:
    if n % f == 0:
      a.append(f)
      n //= f
    else:
      f += 2
  if n != 1:
    a.append(n)
  return a

#重複を検出
def has_duplicates(seq):
  return len(seq) != len(set(seq))


#Christmas D問題
def Christmas(X, DP, DP2, N):
  ans = 0
  b = 0
  for i in reversed(range(0, N+1)):
    if(X-DP[i]>=0):
      b = DP[i]
      X -= b
      ans += DP2[i]
      if(X>=1):
        ans += 1
      N = i+1
      break
    X -= 1
    if(X == 0):
      break
  if not(X == 0):
    ans += Christmas(X, DP, DP2, N)

  return ans

#X = str(input()).split()
#a = [int(x) for x in input().split()]


NX = str(input()).split()
N = int(NX[0])
X = int(NX[1])
DP = [0]*51
DP2 = [0]*51
DP[0] = 1
DP2[0] = 1
ans = 0

for i in range(1, 51):
  DP[i] = DP[i-1]*2+3
  DP2[i] = DP2[i-1]*2+1

ans = Christmas(X, DP, DP2, N)

print(ans)

