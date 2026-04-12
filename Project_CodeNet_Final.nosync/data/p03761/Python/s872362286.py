import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
MOD = 10**9 + 7
alpa = [chr(ord("a")+ i) for i in range(26)]
cnt = [10000000 for i in range(26)]
n = int(input())
li = [list(input()) for i in range(n)]
for i in range(n):
    c = collections.Counter(li[i])
    Key = []
    Val = []
    for key,value in c.items():
        Key.append(ord(key)-97)
        Val.append(value)
    for j in range(26):
        if j in Key:
            for k in range(len(Key)):
                if j == Key[k]:
                    cnt[j] = min(cnt[j],Val[k])
        else:
            cnt[j] = 0
ans = ""
for i in range(len(alpa)):
    ans += alpa[i]*cnt[i]
print(ans)
    