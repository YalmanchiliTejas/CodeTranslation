# import sys
# import math #sqrt,gcd,pi
# import decimal
# import queue # queue
# import bisect
# import heapq # priolity-queue
# import time
# from itertools import product,permutations,\
#     combinations,combinations_with_replacement
# 重複あり順列、順列、組み合わせ、重複あり組み合わせ
# import collections # deque
# from operator import itemgetter,mul
# from fractions import Fraction
# from functools import reduce

mod = int(1e9+7)
# mod = 998244353
INF = 1<<50

def readInt():
    return list(map(int,input().split()))

def main():
    h,w = readInt()
    a = [input() for i in range(h)]
    H = []
    W = []
    for i in range(h):
        f = True
        for j in range(w):
            if a[i][j]=='#':
                f = False
                break
        if f:
            H.append(i)
    for i in range(w):
        f = True
        for j in range(h):
            if a[j][i]=='#':
                f = False
                break
        if f:
            W.append(i)
    ans = []
    for i in range(h):
        if i in H:
            continue
        x = []
        for j in range(w):
            if j in W:
                continue
            x.append(a[i][j])
        ans.append(x)
    for i in range(len(ans)):
        print(''.join(ans[i]))
    return

if __name__=='__main__':
    main()
