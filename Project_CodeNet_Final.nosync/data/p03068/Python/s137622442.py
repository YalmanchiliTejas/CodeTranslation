# coding: utf-8

import sys
input = sys.stdin.readline

N = int(input())
S = input()[:-1]
K = int(input())

moji = S[K - 1]

for s in S:
    print("*" if s != moji else s, end="")

print()
