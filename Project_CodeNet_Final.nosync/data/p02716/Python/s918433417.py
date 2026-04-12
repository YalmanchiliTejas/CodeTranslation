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

def get(n, da):
    mx = 0
    for i in range(n):
        if i%2==1:
            mx += da[i]
    st = [0 for i in range(n)]
    dp = [0 for i in range(n)]
    st[0]=1
    dp[0]=da[0]
    for i in range(2,n):
        if i%2==0:
            st[i]=1
            dp[i]=dp[i-2]+da[i]
        else:
            st[i]=1
            dp[i] = dp[i-3]+da[i]
            if st[i-2]:
                dp[i] = max(dp[i], dp[i-2]+da[i])
    return max(mx, max(dp[n-1], dp[n-2]))

def my_main():
    n = inp()
    da = inp()
    if n%2==0:
        print get(n, da)
    else:
        nda = [da[i] for i in range(n) if i%2==0]
        mx = sum(nda) - min(nda)
        mx = max(mx, max(get(n-1, da[1:]), get(n-1, da[:-1])))
        st = [[0 for i in range(n)]for i in range(3)]
        dp = [[0 for i in range(n)]for i in range(3)]
        st[0][0]=1
        dp[0][0]=da[0]
        for i in range(2,n):
            if st[0][i-2]:
                st[0][i] = 1
                dp[0][i] = dp[0][i-2] + da[i]
            if i-3 >= 0 and st[0][i-3]:
                st[1][i] = 1
                dp[1][i] = dp[0][i-3] + da[i]
            if st[1][i-2]:
                st[1][i] = 1
                dp[1][i] = max(dp[1][i], dp[1][i-2] + da[i])
            if i-3>=0 and st[1][i-3]:
                st[2][i] = 1
                dp[2][i] = dp[1][i-3] + da[i]
            if st[2][i-2]:
                if st[2][i]:
                    dp[2][i] = max(dp[2][i], dp[2][i-2]+da[i])
                else:
                    st[2][i] = 1
                    dp[2][i] = dp[2][i-2]+da[i]
        print max(mx, dp[2][n-1])







my_main()
