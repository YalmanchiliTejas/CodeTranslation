from collections import Counter, defaultdict, deque
import bisect
from sys import stdin, stdout
from itertools import repeat
import math
import random

# sys.stdin = open('input')

def inp():
    re = map(int, raw_input().split())
    if len(re) == 1:
        return re[0]
    return re

def inst():
    return raw_input().strip()

def gcd(x, y):
   while(y):
       x, y = y, x % y
   return x

def my_main():
        n, s = inp()
        da = inp()
        dp = [[0 for i in range(s+1)] for i in range(n+1)]
        sm = [0 for i in range(s+1)]
        dp[0][0] = sm[0] = 1
        mod = 998244353
        for i in range(1, n+1):
            now = da[i-1]
            dp[i][0] = 1
            for j in range(s+1):
                if j>=now:
                    dp[i][j] += sm[j-now]
                dp[i][j] %= mod
            for j in range(s+1):
                sm[j] += dp[i][j]
                sm[j] %= mod
        ans = 0
        for i in range(n+1):
            ans += dp[i][s]*(n-i+1)
            ans %= mod
        print ans



my_main()
