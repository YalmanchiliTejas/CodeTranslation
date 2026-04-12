MOD = 10 ** 9 + 7
INF = 10 ** 10
import sys
sys.setrecursionlimit(100000000)
dy = (-1,0,1,0)
dx = (0,1,0,-1)
from collections import deque

def main():
    n = input()
    k = int(input())

    dp = [[[0] * 2 for _ in range(k + 1)] for _ in range(len(n) + 1)]
    dp[0][0][0] = 1
    for i in range(len(n)):
        dp[i + 1][0][1] = 1
        for j in range(k):
            if n[i] == '0':
                dp[i + 1][j + 1][0] = dp[i][j + 1][0]
                dp[i + 1][j + 1][1] = dp[i][j + 1][1] + dp[i][j][1]*9
            else:
                dp[i + 1][j + 1][0] = dp[i][j][0]
                dp[i + 1][j + 1][1] = dp[i][j + 1][0] + dp[i][j][0]*(int(n[i]) - 1) + dp[i][j + 1][1] + dp[i][j][1]*9
    print(sum(dp[-1][-1]))
if __name__ == '__main__':
    main()