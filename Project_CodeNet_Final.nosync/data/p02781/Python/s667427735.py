import sys, bisect, math, itertools, heapq, collections
from operator import itemgetter
# a.sort(key=itemgetter(i)) # i番目要素でsort
from functools import lru_cache
# @lru_cache(maxsize=None)
sys.setrecursionlimit(10**8)
input = sys.stdin.readline
INF = float('inf')
mod = 10**9 + 7
eps = 10**-7


def inp():
    '''
    一つの整数
    '''
    return int(input())


def inpl():
    '''
    一行に複数の整数
    '''
    return list(map(int, input().split()))


target = list(map(int, list(input())[:-1]))
k = inp()
# dp[digits][notzeros][smaller]
# dp[digits+1][notzeros][smaller]上からi桁目までで条件を満たす数の総数

dp = [[[0] * 2 for _ in range(k + 2)] for i in range(len(target) + 1)]
dp[0][0][0] = 1
for i in range(len(target)):
    for j in range(k + 1):
        for smaller in range(2):
            for x in range(10 if smaller else target[i] + 1):  # 未満なら10進数全て探索
                conditions = 1 if x != 0 else 0  # 条件

                dp[i + 1][j + conditions][smaller or x < target[i]]\
                    += dp[i][j][smaller]
    # print(dp)

ans = sum(dp[len(target)][k])
print(ans)
# print(dp)
