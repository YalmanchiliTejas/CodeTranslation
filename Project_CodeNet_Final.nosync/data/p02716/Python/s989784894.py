# coding: utf-8
# Your code here!
import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
read = sys.stdin.read

n,*a = [int(i) for i in read().split()]

from itertools import accumulate
if n%2==0:
    a1 = list(accumulate([0]+a[::2]))
    a2 = list(accumulate([0]+a[n-1::-2]))[::-1]
    #print(a1,a2)
    print(max(x+y for x,y in zip(a1,a2)))
#elif n==3: print(max(a))
else:
    dp0 = [0]*(n+9)
    dp1 = [0]*(n+9)
    dp2 = [0]*(n+9)
    for i in range(n):
        if i%2==0:
            dp0[i] = dp0[i-2]+a[i]
            if i >= 2:
                dp2[i] = max(dp2[i-2],dp1[i-3],dp0[i-4]) + a[i]
        else:
            dp1[i] = max(dp1[i-2],dp0[i-3]) + a[i]
    #print(dp0)
    #print(dp1)
    #print(dp2)
    print(max(dp2[n-1],dp1[n-2],dp0[n-3]))



