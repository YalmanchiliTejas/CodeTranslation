s = input()
K = int(input())
n = len(s)

dp = [[[0 for _ in range(2)] for _ in range(4)] for _ in range(n+5)]


dp[0][0][0] = 1

for i in range(n):
    for j in range(4):
        for k in range(2):
            nd = int(s[i])  # 今見ている桁の数値
            for d in range(10):
                ni = i+1
                nj = j
                nk = k
                if d != 0:  # 0以外が一個増える
                    nj += 1
                if nj > K:  # これ以上0以外使えないとき
                    continue
                if k == 0:  # そこまでの桁はNと一致しているとき
                    if d > nd:  # Nを超えてしまう
                        continue
                    if d < nd:  # N以下確定である
                        nk = 1
                dp[ni][nj][nk] += dp[i][j][k]

ans = dp[n][K][0] + dp[n][K][1]

print(ans)
