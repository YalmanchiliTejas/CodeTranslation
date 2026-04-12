# coding:utf-8

import sys
import math
import time
import numpy as np
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


#X = str(input()).split()
NM = str(input()).split()
N = int(NM[0])
M = int(NM[1])

# S = [[0 for i in range(W)] for j in range(H)]

if(N==M):
  print("Yes")
else:
  print("No")
