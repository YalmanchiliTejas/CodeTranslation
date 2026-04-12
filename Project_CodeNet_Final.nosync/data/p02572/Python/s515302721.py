from sys import stdin, stdout
import heapq
import cProfile
from collections import Counter, defaultdict, deque
from functools import reduce
import math
from  itertools import accumulate

def get_int():return int(stdin.readline().strip())
def get_tuple():return map(int, stdin.readline().split())
def get_list():return list(map(int, stdin.readline().split()))

n = get_int()
ls = get_list()
mod = 10**9+7
pref_sum = list(accumulate(ls))

ans = 0
for i in range(1,n):
    ans = (ans+ls[i]*(pref_sum[i]-ls[i]))%mod
print(ans)