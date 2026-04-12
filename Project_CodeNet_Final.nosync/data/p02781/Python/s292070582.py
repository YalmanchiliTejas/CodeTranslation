#coding:utf-8
import sys,os
from collections import defaultdict, deque
from fractions import gcd
from math import ceil, floor
sys.setrecursionlimit(10**6)
write = sys.stdout.write
dbg = (lambda *something: print(*something)) if 'TERM_PROGRAM' in os.environ else lambda *x: 0
def main(given=sys.stdin.readline):
    input = lambda: given().rstrip()
    LMIIS = lambda: list(map(int,input().split()))
    II = lambda: int(input())
    XLMIIS = lambda x: [LMIIS() for _ in range(x)]
    YN = lambda c : print('Yes') if c else print('No')
    MOD = 10**9+7

    list_N = list(map(int,list(input())))
    len_N = len(list_N)
    list_N = [0] + list_N

    K = II()
    dp0 = []
    dp1 = []
    for i in range(len_N+1):
        dp0.append([0]*(K+1))
        dp1.append([0]*(K+1))
    for i in range(1,len_N+1):
        dp0[i][0] = 1
    dp0[1][1] = max(list_N[1]-1,0)
    dp1[1][1] = 1
    for i in range(2,len_N+1):
        dp1[i][0] = dp1[i-1][0]
        for j in range(1,K+1):
            num = list_N[i]
            if num > 0:
                dp0[i][j] = dp0[i-1][j-1] * 9 + dp0[i-1][j] + dp1[i-1][j-1] * (num-1) + dp1[i-1][j]
                dp1[i][j] = dp1[i-1][j-1]
            else:
                dp0[i][j] = dp0[i-1][j-1] * 9 + dp0[i-1][j]
                dp1[i][j] = dp1[i-1][j]
                
    print(dp0[len_N][K]+dp1[len_N][K])
    dbg(dp0[len_N][K],dp1[len_N][K])






if __name__ == '__main__':
    main()