# 桁DP
def solve(S, K):
    L = len(S)
    # dp[決定した桁数][未満フラグ][０以外の数字を使った個数]
    dp = [[[0 for _ in range(4)] for _ in range(2)] for _ in range(101)]
    dp[0][0][0] = 1
    for i in range(L):  # 今見ている桁
        D = int(S[i])
        for j in range(2):  # 未満フラグ(0 or 1)
            for k in range(4):  # ０以外の数字を使った個数が0~3
                for d in range(10 if j else D + 1):
                    cnt = k
                    if d != 0:
                        cnt += 1
                    if cnt > K:
                        continue
                    dp[i + 1][j or (d < D)][cnt] += dp[i][j][k]

    return dp[L][0][K] + dp[L][1][K]


def main():
    n = int(input())
    K = int(input())
    print(solve(str(n), K))


if __name__ == '__main__':
    main()
