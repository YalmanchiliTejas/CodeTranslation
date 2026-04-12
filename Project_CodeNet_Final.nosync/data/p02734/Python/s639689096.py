# Knapsack for all segments
N, S = map(int, input().split())
a = list(map(int, input().split()))

mod = 998244353

# dp[x][s] = 最後にとるのが x に対しての部分和がsになる物の総数
#sumdp[x][s]= 最後に撮るのがx番目いぜんに対しての部分和がsになる物の総数

dp = [[0 for i in range(S+1)] for j in range(N+1)]
sumdp = [[0 for i in range(S+1)] for j in range(N+1)]

dp[0][0] = 1
sumdp[0][0] = 1

for i in range(N):
    x = a[i]
    for j in range(S+1):
        if j > x:
            dp[i+1][j] = sumdp[i][j-x]
        elif j==x:
            dp[i+1][j] = i + 1 
        elif j < x:
            dp[i+1][j] = 0
    
        dp[i+1][j] %= mod
        sumdp[i+1][j] = sumdp[i][j]+dp[i+1][j]
        sumdp[i+1][j] %= mod

ans = 0
for i in range(1, N+1):
    ans += dp[i][S]*((N+1-i))
    ans %= mod
print(ans)