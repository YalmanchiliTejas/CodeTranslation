n = input()
m = len(n)
K = int(input())
#状態をもつ：i桁目まで見たときのj（その値は指定された値未満かどうか）において0でない数字がk個ある状態
dp = [[[0] * (K + 1) for _ in range(2)] for _ in range(m + 1)]
dp[0][0][0] = 1

for i in range(1, m+1):
    l = int(n[i-1])
    for k in range(K+1):
        
        #その値通りだった時、l=0だと0の数を増やせないのでi-1桁目でk個になってる個数を引き継ぐ
        if l == 0:
            dp[i][0][k] = dp[i-1][0][k]
        else:
            if k >= 1:
                #l!=0の場合にはまだ増やせるのでi-1桁目でk-1個になってる個数を引き継ぐ
                dp[i][0][k] = dp[i-1][0][k-1]
        

        dp[i][1][k] += dp[i-1][1][k]
        if l != 0:
            dp[i][1][k] += dp[i-1][0][k]
        if k >= 1:
            dp[i][1][k] += 9*dp[i-1][1][k-1]
            if l != 0:
                dp[i][1][k] +=  (l-1)*dp[i-1][0][k-1]

print(dp[m][0][K] + dp[m][1][K])