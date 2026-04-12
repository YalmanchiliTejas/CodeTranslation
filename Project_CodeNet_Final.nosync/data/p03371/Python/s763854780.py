#from statistics import median
#import collections
#aa = collections.Counter(a) # list to list || .most_common(2)で最大の2個とりだせるお a[0][0]
from fractions import gcd
from itertools import combinations,permutations,accumulate # (string,3) 3回
#from collections import deque
from collections import deque,defaultdict,Counter
import decimal
import re
#import bisect
#
#    d = m - k[i] - k[j]
#    if kk[bisect.bisect_right(kk,d) - 1] == d:
#
#
#
# pythonで無理なときは、pypyでやると正解するかも！！
#
#

import sys
sys.setrecursionlimit(10000000)
mod = 10**9 + 7
#mod = 9982443453
def readInts():
  return list(map(int,input().split()))
def I():
  return int(input())
a,b,c,x,y = readInts()
c *= 2
if x > y:
    # 3 通り
    # a,b を x,y個ずつ買う
    # 2枚セットを大きいほう個買う
    # 2枚セットを小さい方買う、のこりは大きい方
    ans = min(a*x + b*y, c * x, c*y + a*(x-y))
else:
    ans = min(a*x + b*y, c*y, c*x+b*(y-x))
print(ans)
