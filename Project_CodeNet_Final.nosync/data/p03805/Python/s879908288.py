import sys
import itertools
# import numpy as np
import time
import math
import heapq
from collections import defaultdict
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 18
MOD = 10 ** 9 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())

n, m = map(int, input().split())
d = [[-1] * n for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    d[a][b] = 1
    d[b][a] = 1

dp = [[-1] * n for i in range(1<<n)]
#訪れた集合がs、今いる点がvの時０に戻る最短経路
def rec(s,v,dp):
    if dp[s][v] >= 0:
        return dp[s][v]
        
    if s == (1<<n)-1:
        dp[s][v] = 1
        return 1
    
    res = 0
    for u in range(n):
        if (s>>u&1) == 0 and d[v][u] == 1:
            res += rec(s|(1<<u),u,dp)
    dp[s][v] = res
    return res

print(rec(1,0,dp))