#154_E
n = input()
s = len(n)
x = int(input())

#dp[i][flg][cnt] ... i桁目まで、未満フラグ、0以外の数
dp = [[[0 for _ in range(4)] for _ in range(2)] for _ in range(s+1)]
dp[0][0][0] = 1

for i in range(1, s+1):
    for k in [0, 1, 2, 3]:
        if n[i-1] == '0':
            dp[i][0][k] += dp[i-1][0][k]
        else:
            dp[i][1][k] += dp[i-1][0][k]
            if k > 0:
                dp[i][0][k] += dp[i-1][0][k-1]
                dp[i][1][k] += dp[i-1][0][k-1] * (int(n[i-1]) - 1)
        
        dp[i][1][k] += dp[i-1][1][k]
        if k > 0:
            dp[i][1][k] += dp[i-1][1][k-1] * 9
   
print(dp[s][0][x] + dp[s][1][x])