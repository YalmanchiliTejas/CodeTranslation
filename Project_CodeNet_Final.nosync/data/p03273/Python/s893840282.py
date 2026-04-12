import sys
from sys import exit
from collections import deque
from bisect import bisect_left, bisect_right, insort_left, insort_right #func(リスト,値)
from heapq import heapify, heappop, heappush
from math import *

sys.setrecursionlimit(10**6)
INF = 10**20
MOD = 10**9+7

def mint():
    return map(int,input().split())
def lint():
    return map(int,input().split())
def judge(x, l=['Yes', 'No']):
    print(l[0] if x else l[1])
def lprint(l, sep='\n'):
    for x in l:
        print(x, end=sep)

H,W = mint()
A = [input() for _ in range(H)]
I = []
J = []

for i in range(H):
    for j in range(W):
        if A[i][j]=='#':
            I.append(i)
            break

for j in range(W):
    for i in range(H):
        if A[i][j]=='#':
            J.append(j)
            break

            
S = [[0]*len(J) for _ in range(len(I))]

for i in range(len(I)):
    for j in range(len(J)):
        print(A[I[i]][J[j]],end='')
    print('')