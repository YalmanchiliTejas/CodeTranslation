S = input()
N = len(S)
K = int(input())



dp = [[[0 for _ in range(5)] for _ in range(2)] for _ in range(N+1)]
dp[0][0][0] = 1
"""
遷移
dp[i][1][j] -> dp[i+1][1][j] : i-1桁目までに0以外の数字がj個あり、i桁目に0を入れた
dp[i][1][j] -> dp[i+1][1][j+1] : i-1桁目までに0以外の数字がj個あり、i桁目に0以外を入れた
dp[i][0][j] -> dp[i+1][1][j] : i-1桁目がSと一致していて、i-1桁目までに0以外の数字がj個あり、までに0以外の数字がj個あり、i桁目に0を入れた
dp[i][0][j] -> dp[i+1][1][j] : i-1桁目がSと一致していて、i-1桁目までに0以外の数字がj個あり、までに0以外の数字がj個あり、i桁目に0以外を入れた
dp[i][0][j] -> dp[i+1][0][j+?] : i桁目までSと一致。i桁目が0以外なら、?=1

"""

for i in range(N):
    for k in range(4):
        for j in range(10):
        


            if j == 0:
                 # i桁目に0をあてた
                dp[i+1][1][k] += dp[i][1][k]
            else:
                # i桁目に0以外をあてた
                dp[i+1][1][k+1] += dp[i][1][k]


            if j < int(S[i]):
                if j == 0:
                    dp[i+1][1][k] += dp[i][0][k]
                else:
                    dp[i+1][1][k+1] += dp[i][0][k]
            elif j == int(S[i]):
                if j == 0:
                    dp[i+1][0][k] += dp[i][0][k]
                else:
                    dp[i+1][0][k+1] += dp[i][0][k]


print(dp[-1][0][K] + dp[-1][1][K])
