# -*- coding: utf-8 -*-
import sys
import math

N,X = list(map(int, input().rstrip().split()))
#-----

## レベルnバーガーの、層の数
def material(n):
    return 2**(n+2)-3

## レベルnバーガーの、Pattyの数
def patty(n):
    return 2**(n+1)-1

cnt=0
while N > 0:
    half = material(N) // 2 + 1
    
    if X == half:
        cnt += patty(N-1) + 1
        break
    elif X == 1:
        break
    elif X > half:
        cnt += patty(N-1) + 1
        N -= 1
        X -= half
    elif 1 < X < half:
        N -= 1
        X -= 1

    ## last    
    if N == 0:
        cnt += 1

print(cnt)
