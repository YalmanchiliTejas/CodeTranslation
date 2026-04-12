# coding:UTF-8
import sys
from math import factorial

MOD = 10 ** 9 + 7
INF = float('inf')

A, B, C, X, Y = list(map(int, input().split()))     # スペース区切り連続数字

mcost = INF

cnum = max(X, Y)
for i in range(cnum+1):
    anum = max(0, (X - i))
    bnum = max(0, (Y - i))
    cost = A * anum + B * bnum + C * i * 2
    mcost = min(mcost, cost)

print("{}".format(mcost))
