S = input()
K = int(input())
N = len(S)  # 桁数

# dp[i][j][k] : i桁目まで見て、非ゼロがj回出て、
# k=0ならそれまでの桁はNと一致、k=1なら既にN以下が決定してる
dp = [[[0] * 2 for _ in range(4)] for _ in range(105)]
dp[0][0][0] = 1

# i, j, kは遷移前のdpの状態
# ni, nj, nkは遷移先のdpの状態
for i in range(N):
    nd = int(S[i])
    for j in range(4):
        for k in range(2):
            for d in range(10):
                ni = i + 1
                nj = j
                nk = k
                if d != 0:  # 非ゼロを使うのでjを1つ増やす
                    nj += 1
                if nj > K:
                    continue
                if k == 0:
                    if d > nd:
                        continue
                    if d < nd:
                        nk += 1
                dp[ni][nj][nk] += dp[i][j][k]

ans = dp[N][K][0] + dp[N][K][1]
print(ans)
