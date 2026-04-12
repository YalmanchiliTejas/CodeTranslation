#from statistics import median
import collections
#aa = collections.Counter(a) # list to list || .most_common(2)で最大の2個とりだせるお a[0][0]
#from fractions import gcd
#from itertools import combinations # (string,3) 3回
#from collections import deque
#from collections import deque,defaultdict
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
n = I()
alpha = [0] * (ord('z') - ord('a') + 1)
for i in range(n):
    s = input()
    dic = collections.Counter(s)
    if i == 0:
        for k,v in dic.items():
            alpha[ord(k)-ord('a')] += v
    else:
        for alnum in range(ord('z') - ord('a')+1):
            alstr = chr(ord('a') + alnum)
            if alstr in dic.keys():
                alpha[ord(alstr)-ord('a')] = min(dic[alstr],alpha[ord(alstr)-ord('a')])
            else:
                alpha[ord(alstr)-ord('a')] = 0
ans = ""
for i in range(ord('z') - ord('a')+1):
    if alpha[i] != 0:
        ans += chr(ord('a') + i) * alpha[i]
print(ans)
