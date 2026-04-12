import sys

def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))  #空白あり
def S(): return sys.stdin.readline().rstrip()

N,S = map(int,S().split())
A = [0] + LI()
mod = 998244353

# f(h,i,C)を h <= x_1 < … < x_k <= i かつ A_(x_1) + … + A_(x_k) = C を満たす(x_1,…,x_k)の組の個数とする
# そして F(i,C) = f(1,i,C) + … + f(i,i,C) と定める
# 求めたい値は、F(1,S) + … + F(N,S) である
# すると(大体) F(i,C) = F(i-1,C-A_i) + F(i-1,C) + f(i,i,C) が成り立つ 
# dp[i][C] = F(i,C) としてdpする

dp = [[0]*(S+1) for i in range(N+1)]

for i in range(1,N+1):
    for j in range(S+1):
        if j == 0:
            dp[i][j] = i
        elif i >= 1:
            if j > A[i]:
                dp[i][j] = (dp[i - 1][j - A[i]] + dp[i - 1][j]) % mod
            elif j == A[i]:
                dp[i][j] = (dp[i - 1][j - A[i]] + dp[i - 1][j] + 1) % mod
            else:
                dp[i][j] = dp[i - 1][j]

ans = 0
for i in range(1,N+1):
    ans = (ans + dp[i][S]) % mod

print(ans)