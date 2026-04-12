import sys
import math
import heapq
mod=10**9+7
inf=float("inf")
from math import sqrt
from collections import deque
from collections import Counter
from math import ceil
input=lambda: sys.stdin.readline().strip()
sys.setrecursionlimit(11451419)
from decimal import Decimal #floatの高精度ver, 渡すのはstr型で
from functools import lru_cache
#メモ化再帰defの冒頭に毎回 @lru_cache(maxsize=10**10)
#引数にlistはだめ
#######ここまでテンプレ#######
#ソート、"a"+"b"、再帰ならPython3の方がいい
#######ここから天ぷら########

from itertools import permutations as per
n,m=map(int,input().split())
A=[[] for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    a-=1 ;b-=1
    A[a].append(b)
    A[b].append(a)

ans=0
for bit in per([i for i in range(1,n)]):
    # print(bit)
    peanut=0
    bit=[0]+list(bit)
    for i in range(n-1):
        if not bit[i] in A[bit[i+1]]:
            peanut=1
            break
    else:
        ans+=1
    

print(ans)