# https://atcoder.jp/contests/abc154/tasks/abc154_e
# 桁DPっぽいよなぁ => O

"""
memo
dp0[i][j]
  上からi桁目まで決めて，0でない桁がj個あり
  Nより小さいことが確定している (less)
dp1[i][j]
  上からi桁目まで決めて，0でない桁がj個あり
  Nより小さいことが確定していない (i桁目まで同じ)

通常の再帰
rec
"""

S = input()
K = int(input())
N = len(S)


dp0 = [[0] * (K + 2) for _ in range(N + 1)]
dp1 = [[0] * (K + 2) for _ in range(N + 1)]
dp0[0][0] = 1

# i桁目まで
for i in range(N):
    dig = int(S[i])

    # 0でない桁の個数がj個
    for j in range(K + 1): 
        # 選ぶ数字がk=0..9
        for k in range(10):
            nj = j if k == 0 else j + 1
            if k < dig:
                dp1[i + 1][nj] += dp0[i][j] + dp1[i][j]
            elif k == dig:
                dp1[i + 1][nj] += dp1[i][j]
                dp0[i + 1][nj] += dp0[i][j]
            else:
                dp1[i + 1][nj] += dp1[i][j]

ans = dp0[N][K] + dp1[N][K]
print(ans)