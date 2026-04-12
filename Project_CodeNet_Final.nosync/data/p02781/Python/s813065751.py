n = input()
k = int(input())
n_len = len(n)

dp = [[[0]*(k+2) for _ in range(2)] for _ in range(n_len+1)]
dp[0][False][0] = 1

for i in range(n_len):
    for j in range(k+1):
        # iでTrue、i+1でTrueのとき（i桁目が０でないとき、ｋは減る）
        # かける９の意味は０以外のなんでもいい数ということ
        dp[i+1][True][j+1] += dp[i][True][j]*9
        # iでTrue、i+1でTrueのとき（i桁目が０のとき、ｋは減らない）
        # ０一択なので＊１
        dp[i+1][True][j] += dp[i][True][j]*1

        # i桁目まで等しい状態からi+1桁目で小さくなるとき
        # i⁺1桁目が０だったら小さくなりようがないので考えない
        # i+1桁目が０のときはもう一つ下の場合分けに入っている
        if int(n[i]) != 0:
            dp[i+1][True][j+1] += dp[i][False][j]*(int(n[i])-1)
            dp[i+1][True][j] += dp[i][False][j]
            

        # i桁目まで等しい状態からi+1桁目も等しい状態のとき
        if int(n[i]) != 0:
            dp[i+1][False][j+1] = dp[i][False][j]
        else:
            dp[i+1][False][j] = dp[i][False][j]

print(dp[-1][False][k] + dp[-1][True][k])