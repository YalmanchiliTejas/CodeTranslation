import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N = list(input())
K = int(input())
length = len(N)

dp = [[[0]*2 for _ in range(K+1)] for _ in range(length+1)]
dp[0][0][1] = 1
for i in range(length):
    n = int(N[i])
    for k in range(K+1):
        if k==K:
            dp[i+1][k][0]+=dp[i][k][0]
            if n==0:
                dp[i+1][k][1]+=dp[i][k][1]
            else:
                dp[i+1][k][0]+=dp[i][k][1]
            continue
        for j in range(10):
            if j==0:
                if n==0:
                    dp[i+1][k][0]+=dp[i][k][0]
                    dp[i+1][k][1]+=dp[i][k][1]
                else:
                    dp[i+1][k][0]+=dp[i][k][0]+dp[i][k][1]
            elif j==n:
                dp[i+1][k+1][1]+=dp[i][k][1]
                dp[i+1][k+1][0]+=dp[i][k][0]
            elif j<n:
                dp[i+1][k+1][0]+=dp[i][k][0]+dp[i][k][1]
            else:
                dp[i+1][k+1][0]+=dp[i][k][0]
print(sum(dp[-1][K]))