MOD = 10 ** 9 + 7
INF = 10 ** 20
import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)
from collections import defaultdict
dy = (-1,0,1,0)
dx = (0,1,0,-1)

def main():
    n = int(input())
    a = list(map(int,input().split()))

    dp = [{(i - 1)//2: -INF, (i + 1)//2: -INF} for i in range(n + 1)]
    dp[0][0] = 0
    dp[1][0] = 0
    dp[1][1] = a[0]
    for i in range(1,n):
        if i%2 == 1:
            m1,m2 = (i + 2)//2,i//2
            dp[i + 1][m1] = max(dp[i - 1][m1 - 1] + a[i],dp[i][m1])
            dp[i + 1][m2] = max(dp[i - 1][m2 - 1] + a[i],dp[i][m2])
        else:
            m1,m2 = (i + 2)//2,i//2
            dp[i + 1][m1] = dp[i - 1][m1 - 1] + a[i]
            dp[i + 1][m2] = max(dp[i - 1][m2 - 1] + a[i],dp[i][m2])

    print(dp[n][(n//2)])

if __name__ =='__main__':
    main()  
