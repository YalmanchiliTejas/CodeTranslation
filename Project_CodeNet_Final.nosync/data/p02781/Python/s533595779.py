N = list(map(int, input()))     # 整数を桁毎のリストとして読み込む
L = len(N)
K = int(input())
D = K + 2                       # 状態数
dp = [[[0] * D for i in range(L + 1)] for j in range(2)]

def min2(x,y):
    return x if x < y else y

"""
dp[0][i][*]: 上からi桁目までが N と一致
dp[1][i][*]: 上からi桁目までで N である事が確定
dp[*][*][j]: 0 でない数字の個数が j 個
"""
dp[0][0][0] = 1
for i in range(L):
    for j in range(D):
        for k in range(10):
            if k < N[i]:
                dp[1][i+1][min2(j + (k!=0), D-1)] += dp[0][i][j] + dp[1][i][j]
            elif k == N[i]:
                dp[0][i+1][min2(j + (k!=0), D-1)] += dp[0][i][j]
                dp[1][i+1][min2(j + (k!=0), D-1)] += dp[1][i][j]
            else:
                dp[1][i+1][min2(j + (k!=0), D-1)] += dp[1][i][j]

res = dp[0][L][K] + dp[1][L][K]
print(res)