#### import ####
import sys
import math
from collections import defaultdict

#### 設定 ####
sys.setrecursionlimit(10**7)
def input():
    return sys.stdin.readline()[:-1]

#### 定数 ####
mod = 10**9 + 7

#### 読み込み ####
def I(): return int(input())
def II(): return map(int, input().split())
def III(): return list(map(int, input().split()))
def Line(N):
    read_all = [tuple(map(int, input().split())) for _ in range(N)]
    return map(list,zip(*read_all))

#################

A,B,C,X,Y = II()

if A+B<2*C:
    print(A*X+B*Y)
else:
    if X<Y:
        if B>2*C:
            print(X*2*C+(Y-X)*2*C)
        else:
            print(X*2*C+(Y-X)*B)
    else:
        if A>2*C:
            print(Y*2*C+(X-Y)*2*C)
        else:
            print(Y*2*C+(X-Y)*A)