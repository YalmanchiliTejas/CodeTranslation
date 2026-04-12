# -*- coding: utf-8 -*-

## Library

import sys
from fractions import gcd
import math
from math import ceil,floor
import collections
from collections import Counter
import itertools
import copy

## input

# N=int(input())
# A,B,C,D=map(int, input().split())
# S = input()
# yoko = list(map(int, input().split()))
# tate = [int(input()) for _ in range(N)]
# N, M = map(int,input().split()) 
#    P = [list(map(int,input().split())) for i in range(M)]
#    S = []
#    for _ in range(N):
#        S.append(list(input()))
H,W = map(int,input().split()) 

S = []
for _ in range(H):
    S.append(list(input()))

R = []
C = []

for i in range(H):
    flag = 1
    for j in range(W):
        if S[i][j] == "#":
            flag = 0
            break
    if flag == 1:
        R.append(i)

for i in range(W):
    flag = 1
    for j in range(H):
        if S[j][i] == "#":
            flag = 0
            break
    if flag == 1:
        C.append(i)

C.sort(reverse=True)
R.sort(reverse=True)

if len(C)>0:
    for i in range(len(C)):
        for j in range(H):
            del S[j][C[i]]

if len(R)>0:
    for i in range(len(R)):
        del S[R[i]]

for i in range(len(S)):
    for j in range(len(S[i])):
        print(S[i][j], end='')
    print()