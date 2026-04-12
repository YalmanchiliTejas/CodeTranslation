import math
#import numpy as np
import queue
from collections import deque,defaultdict
import heapq as hpq
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)

def main():
    n,a,b,c,d = map(int,ipt().split())
    mod = 10**9+7

    #nCrをmodで割った余りを求める。Nに最大値を入れて使用。
    N = n
    g1 = [1, 1] # 元テーブル
    g2 = [1, 1] #逆元テーブル
    inverse = [0, 1] #逆元テーブル計算用テーブル
    def cmb(n,r,mod):
        if r<0 or r>n :
            return 0
        r = min(r,n-r)
        return g1[n]*g2[r]*g2[n-r]%mod
    for i in range(2,N+1):
        g1.append((g1[-1]*i)%mod)
        inverse.append((-inverse[mod % i]*(mod//i))%mod)
        g2.append((g2[-1]*inverse[-1])%mod)

    dp = [[0]*(n+1) for i in range(n+1)]
    dp[a][0] = 1
    for i in range(c,d+1):
        if i*a > n:
            break
        dp[a][a*i] = g1[n]*g2[n-a*i]%mod*g2[i]%mod*pow(g2[a],i,mod)%mod

    for i in range(a+1,b+1):
        dpi = dp[i]
        dppi = dp[i-1]
        for j in range(0,n+1):
            sm = dppi[j]
            for k in range(c,min(j//i+1,d+1)):
                sm = (sm+dppi[j-i*k]*g1[n-j+i*k]%mod*g2[n-j]%mod*g2[k]%mod*pow(g2[i],k,mod)%mod)%mod
            dpi[j] = sm
    print(dp[b][n])

    return

if __name__ == '__main__':
    main()
