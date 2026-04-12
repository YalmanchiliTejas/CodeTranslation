N = int(input())
K = int(input())
dp = [[[0]*2 for _ in range(4)] for _ in range(105)]
# dp[i][j][k]:上からi桁まで決めて0でない数字をj個用いた数字で
# k = 0の時Nと一致,k=1の時N未満が確定
# 求める答えはdp[len(str(N))][K][0] + dp[len(str(N))][K][1]
# k=0からk=1の遷移が不可逆

dp[0][0][0] = 1
length = len(str(N))
for i in range(length):
    for j in range(4):
        for k in range(2):
            next_digit = int(str(N)[i])
            for d in range(10):
                ni = i+1
                nj = j
                nk = k
                if d != 0:
                    nj += 1
                if nj > K:
                    continue
                if k == 0:
                    if next_digit < d:
                        continue
                    if next_digit > d:
                        nk = 1
                dp[ni][nj][nk] += dp[i][j][k]
ans = dp[length][K][0] + dp[length][K][1]
print(ans)
