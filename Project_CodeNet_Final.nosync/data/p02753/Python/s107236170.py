import heapq
from collections import deque
from enum import Enum
import sys
import math
from _heapq import heappush, heappop

BIG_NUM = 2000000000
MOD = 1000000007
EPS = 0.000000001


#入力
s=input()
#n=int(input())
#a,b=map(int,input().split())
#l=list(map(int,input().split()))

#2次元配列
#2dimls=[[0 for i in range(2)] for j in range(n)]

ans="Yes"
if s=="AAA" or s=="BBB":
    ans="No"
print(ans)