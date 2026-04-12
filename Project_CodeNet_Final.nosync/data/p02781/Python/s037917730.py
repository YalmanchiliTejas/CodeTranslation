N = int(input().strip())
K = int(input().strip())

# dp = [頭からi桁目][未満フラグ][これまでに出てきた0以外の数]
dp = [[[0 for i in range(K+1)] for f in range(2)] for n in range(len(str(N)))]

# init
Ni = int(str(N)[0])
# 頭が0
dp[0][1][0] = 1
if Ni == 1:
    dp[0][0][1] = 1  # 頭が1
else:
    dp[0][0][1] = 1  # 頭がNi
    dp[0][1][1] = Ni-1  # 頭が1~(Ni-1)

# print(dp[0])
for i in range(1,len(str(N))):
    Ni = int(str(N)[i])
    for k in range(K+1):
        # N未満であることが確定している
        dp[i][1][k] += dp[i-1][1][k]  # 0
        if k < K:
            dp[i][1][k+1] += dp[i-1][1][k]*9  # 1~9

        # N未満であることが確定していない(頭からi桁目までがNと一致している)
        if Ni == 0:
            # 0を選ぶしかない。未満フラグは立たない
            dp[i][0][k] += dp[i-1][0][k]
        elif Ni == 1:
            # 0 未満フラグが立つ
            dp[i][1][k] += dp[i-1][0][k]
            # 1 未満フラグが立たない
            if k < K:
                dp[i][0][k+1] += dp[i-1][0][k]
        else:
            # 0 未満フラグが立つ
            dp[i][1][k] += dp[i-1][0][k]
            # 1~(Ni-1) 未満フラグが立つ
            if k < K:
                dp[i][1][k+1] += dp[i-1][0][k]*(Ni-1)
            # Ni 未満フラグが立たない
            if k < K:
                dp[i][0][k+1] += dp[i-1][0][k]
    # print(dp[i])
print(dp[-1][0][K]+dp[-1][1][K])
