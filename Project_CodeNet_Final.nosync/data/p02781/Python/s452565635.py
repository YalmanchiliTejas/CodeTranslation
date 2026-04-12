N = int(input())
K = int(input())

X = str(N+1)

dp = [[[0] * (K+1) for _ in range(2)] for _ in range(len(X)+1)]
#dp[i桁目][未満フラグ、0ならばそこまでの桁はNと同じ。1ならばすでにN以下が確定][k個の非ゼロを使う]
dp[0][0][0] = 1

for i in range(len(X)):
    D = int(X[i])
    for j in range(2):
        for k in range(K+1):
            for d in range(10 if j == 1 else D+1):
                if k + (d != 0) <= K:
                    dp[i+1][j | (d<D)][k+(d != 0)] += dp[i][j][k]


print(dp[-1][-1][-1])