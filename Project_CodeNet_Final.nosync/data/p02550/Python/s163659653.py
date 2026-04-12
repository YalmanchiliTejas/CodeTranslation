#from statistics import median
#import collections
#aa = collections.Counter(a) # list to list || .most_common(2)で最大の2個とりだせるお a[0][0]
from math import gcd
from itertools import combinations,permutations,accumulate, product # (string,3) 3回
#from collections import deque
from collections import deque,defaultdict,Counter
import decimal
import re
import math
import bisect
import heapq
#
#
#
# pythonで無理なときは、pypyでやると正解するかも！！
#
#
# my_round_int = lambda x:np.round((x*2 + 1)//2)
# 四捨五入g
#
# インデックス系
# int min_y = max(0, i - 2), max_y = min(h - 1, i + 2);
# int min_x = max(0, j - 2), max_x = min(w - 1, j + 2);
#
#
import sys
sys.setrecursionlimit(10000000)
mod = 10**9 + 7
#mod = 9982443453
#mod = 998244353
INF = float('inf')
from sys import stdin
readline = stdin.readline
def readInts():
  return list(map(int,readline().split()))
def readTuples():
    return tuple(map(int,readline().split()))
def I():
    return int(readline())
n,x,m = readInts()
lis = []
prv = None
dic = defaultdict(int)
for i in range(m):
    if i == 0:
        A = x%m
        lis.append(A)
        dic[A] = 1
    else:
        A = (A*A)%m
        if dic[A]:
            prv = A
            break
        else:
            dic[A] = 1
        lis.append(A)
cnt = None
for i in range(len(lis)):
    if lis[i] == prv:
        cnt = i
        break
if cnt == None:
    cnt = len(lis)
front_arr = lis[:cnt]
loop_arr = lis[cnt:]
if x == 0:
    print(0)
    exit()
len_loop_arr = len(loop_arr)
if n < cnt:
    ans = sum(front_arr[:n])
else:
    ans = sum(front_arr)
    sum_loop_arr = sum(loop_arr)
    n -= cnt

    loop = n//len_loop_arr
    rest = n - (loop*len_loop_arr)
    mid = loop * sum_loop_arr
    ans += mid
    ans += sum(loop_arr[:rest])
print(ans)
