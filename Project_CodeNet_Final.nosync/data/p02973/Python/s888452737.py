import sys

def I(): return int(sys.stdin.readline().rstrip())

N = I()
A = [-I() for i in range(N)]

# Aの最大非増加部分列の長さを求めればOK

from bisect import bisect_left,bisect

def LNDS(l):  #リストlのLNDSの長さを求める
    dp = [float('inf')]*(len(l)+1)
    dp[0] = -float('inf')
    for i in range(len(l)):
        j = bisect(dp,l[i])
        dp[j] = l[i]
    return bisect_left(dp,float('inf'))-1

print(LNDS(A))