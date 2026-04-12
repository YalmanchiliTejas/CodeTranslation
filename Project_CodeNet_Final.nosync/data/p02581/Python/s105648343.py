'''
自宅用PCでの解答
'''
import math
#import numpy as np
import itertools
import queue
import bisect
from collections import deque,defaultdict
import heapq as hpq
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)
mod = 10**9+7
dir = [(-1,0),(0,-1),(1,0),(0,1)]
alp = "abcdefghijklmnopqrstuvwxyz"

def main():
    n = int(ipt())
    a = [int(i)-1 for i in ipt().split()]
    dp = [[-10000]*n for i in range(n)]
    add = 0
    ma = 0
    manm = [-10000]*n
    manm[a[0]] = 0
    manm[a[1]] = 0

    dp[a[0]][a[1]] = 0
    for k in range(3,3*n,3):
        a0 = a[k-1]
        a1 = a[k]
        a2 = a[k+1]

        if a0 == a1 == a2:
            add += 1

        elif a0 != a1 != a2 != a0:
            pdp0 = dp[a0][a0]*1
            pdp1 = dp[a1][a1]*1
            pdp2 = dp[a2][a2]*1
            dp0 = dp[a0]
            dp1 = dp[a1]
            dp2 = dp[a2]

            #[a0][x],[a1][x],[a2][x]を更新
            for i in range(n):
                dp0[i] = manm[i]
                dp1[i] = manm[i]
                dp2[i] = manm[i]

            #[a1][a2]を更新
            if ma < pdp0+1:
                dp1[a2] = pdp0+1
            else:
                dp1[a2] = ma
            #[a0][a2]を更新
            if ma < pdp1+1:
                dp0[a2] = pdp1+1
            else:
                dp0[a2] = ma
            #[a0][a1]を更新
            if ma < pdp2+1:
                dp0[a1] = pdp2+1
            else:
                dp0[a1] = ma

            #manm,maの更新
            manm[a0] = max(dp0)
            manm[a1] = max(dp1)
            manm[a2] = max(dp2)
            if manm[a2] < dp1[a2]:
                manm[a2] = dp1[a2]
            if manm[a2] < dp0[a2]:
                manm[a2] = dp0[a2]
            if manm[a1] < dp0[a1]:
                manm[a1] = dp0[a1]
            ma = max(manm)

        else:
            if a0 == a1:
                p = a0
                q = a2
            elif a1 == a2:
                p = a1
                q = a0
            else:
                p = a2
                q = a1
            pdpp = dp[p][p]*1
            pdpq = dp[q][q]*1
            dpp = dp[p]
            dpq = dp[q]

            do = []
            dpip = [dp[i][p] for i in range(n)]
            #[q][x]を更新
            for i in range(n):
#                print("A",i,manm[i],dpp[i],dpip[i])
                if manm[i] >= dpp[i]+1 and manm[i] >= dpip[i]+1:
                    dpq[i] = manm[i]
                else:
                    if dpp[i] > dpip[i]:
                        dpq[i] = dpp[i]+1
                    else:
                        dpq[i] = dpip[i]+1
                do.append((q,dpq[i]))
                do.append((i,dpq[i]))
            #[p][x]を更新
            for i in range(n):
                if manm[i] > dpp[i]:
                    dpp[i] = manm[i]
                    do.append((p,manm[i]))
            #[p][p]を更新
            if ma > pdpq+1:
                dpp[p] = ma
            else:
                dpp[p] = pdpq+1
            do.append((p,dpp[p]))
            #[p][q]を更新
            if ma > pdpp+1:
                dpp[q] = ma
            else:
                dpp[q] = pdpp+1
            do.append((p,dpp[q]))
            do.append((q,dpp[q]))

            #manm,maの更新
            for i,j in do:
                if manm[i] < j:
                    manm[i] = j
            ma = max(manm)

    dp[a[-1]][a[-1]] += 1

    ma = 0
    for i in dp:
        for j in i:
            if j > ma:
                ma = j

    print(ma+add)



    return None

if __name__ == '__main__':
    main()
