import os, sys, re, math

N,X = list(map(int,input().split(' ')))

memo_length = [0 for i in range(51)]
memo_patties = [0 for i in range(51)]
memo_length[0] = 1
memo_patties[0] = 1

for i in range(1,51):
    memo_length[i] = memo_length[i-1] * 2 + 3
    memo_patties[i] = memo_patties[i-1] * 2 + 1

def doit(level,x):
    if x == 0:
        return 0
    if x >= memo_length[level]:
        return memo_patties[level]

    tmp = memo_length[level-1]
    ret = 0

    if x >= 1:
        ret += doit(level-1, x-1)
    if x >= tmp + 2:
        ret += 1
        ret += doit(level-1, x-tmp-2)

    return ret

print(doit(N,X))
