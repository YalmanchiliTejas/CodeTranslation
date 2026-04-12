def I(): return int(input())
def MI(): return map(int, input().split())
def LMI(): return list(map(int, input().split()))


# 桁DPによる数え上げ
# dp[i][smaller][j] = 上からi桁目までで0でない桁がj個ある数字の数
N = input()
K = I()
l = len(N)
dp = [[[0] * (K + 1) for _ in range(2)] for _ in range(l + 1)]
dp[0][False][0] = 1
for i in range(1, l + 1):
    N_i = int(N[i - 1])
    for smaller in [True, False]:  # smaller := Nより小さいことが確定している
        for j in range(K + 1):
            for d in range((9 if smaller else N_i) + 1):
                if j + (0 if d == 0 else 1) <= K:
                    dp[i][smaller or d < N_i][j + (0 if d == 0 else 1)] += dp[i - 1][smaller][j]

print(dp[l][True][K] + dp[l][False][K])
