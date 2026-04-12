N=int(input())
K=int(input())
s=str(N)
N=len(s)

# dp[i][smaller][k] :=i桁目までで0以外の数を使用したのがk個である数の個数。
# smallerが1ならNより小さく、0ならNと等しい数であるとする。
dp=[[[0]*(K+2) for j in range(2)] for i in range(N+1)]
dp[0][0][0]=1
for i in range(N):
  for k in range(K+1):
    ni=int(s[i])
    # i桁目まででNより小さいならi+1桁目は何でも良い
    dp[i+1][1][k+1]+=dp[i][1][k]*9 # i+1桁目が0以外
    dp[i+1][1][k]+=dp[i][1][k]     # i+1桁目が0
    # i桁目まででNと同じで、i+1桁目はNより小さい時
    if ni>0:
      dp[i+1][1][k+1]+=dp[i][0][k]*(ni-1) # i+1桁目が0以外
      dp[i+1][1][k]+=dp[i][0][k]          # i+1桁目が0以外
    # i桁目までNと同じで、i+1桁目もNと同じ数の時
    if ni>0:
      dp[i+1][0][k+1]=dp[i][0][k] # i+1桁目が0以外
    else:
      dp[i+1][0][k]=dp[i][0][k]   # i+1桁目が0
print(dp[N][0][K]+dp[N][1][K])
