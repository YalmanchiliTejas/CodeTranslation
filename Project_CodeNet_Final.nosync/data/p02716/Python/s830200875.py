# coding: utf-8
import sys
from functools import lru_cache
sys.setrecursionlimit(10 ** 7)

N = int(input())
A = list(map(int, input().split()))
INF = 10 ** 17

@lru_cache(None)
def F(index, n):
    '''index以降、n個選ぶ最大値を返す'''
    if index >= N: 
        return -INF
    if N - index < 2 * n - 1:  # n個選べない
        return -INF
    if n == 0:
        return 0
    elif n == 1:
        return max(A[index:])
    ret = max(A[index] + F(index+2, n-1), F(index+1, n))
    return ret

answer = F(0, N//2)
print(answer)
