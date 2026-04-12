#!/usr/bin/env python3

#import
#import math
#import numpy as np
#= int(input())
#= input()
N, X, M = map(int, input().split())

def mod(x):
    return x % M

a = X

i = 0

ans = 0
last = -1

dic = []

while a != 0 and i < N:
    ans += a
    a = mod(a * a)
    i += 1

    if a in dic:
        last = dic.index(a)
        break

    dic.append(a)


if i != N and a != 0:
    tdic = dic[last:]
    if N - i >= len(tdic):
        sdic = sum(tdic)
        ans += sdic * ((N - i) // len(tdic))

    for j in range((N - i) % len(tdic)):
        ans += tdic[j]

print(ans)