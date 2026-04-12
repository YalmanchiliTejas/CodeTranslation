import sys
n = int(input())
k = int(input())

keta = len(str(n))
# dp[i桁まで検査済み][coincidence][0以外の個数]
dp = [[[0] * (k + 1) for i in range(2)] for j in range(keta + 1)]

dp[0][1][0] = 1
for a in range(1, keta + 1):
    digit = int(str(n)[a - 1])
    for b in range(2):
        for c in range(k + 1):
            if b == 0 and c == k:
                # 最大値と不一致で0以外の個数がk個になる
                dp[a][b][c] += dp[a-1][0][k] * 1
                dp[a][b][c] += dp[a-1][0][k-1] * 9
                # d != 0(仮に3) -> 0
                # d == 0 -> 0にすると最大値と一致するのでだめ
                dp[a][b][c] += dp[a-1][1][k] * (1 if digit != 0 else 0)
                # d != 0(仮に3) -> 1, 2(0はkにならないのでだめ、3はb == 1になるのでだめ)
                # d == 0 -> 0にするとkが増えないのでだめ
                dp[a][b][c] += dp[a-1][1][k-1] * (digit - 1 if digit != 0 else 0)
            elif b == 0 and c != k:
                # 最大値と不一致で0以外の個数がc個になる
                dp[a][b][c] += dp[a-1][0][c] * 1
                dp[a][b][c] += 0 if c == 0 else dp[a-1][0][c-1] * 9
                dp[a][b][c] += dp[a-1][1][c] * (1 if digit != 0 else 0)
                dp[a][b][c] += 0 if c == 0 else dp[a-1][1][c-1] * (digit - 1 if digit != 0 else 0)
            elif b == 1 and c == k:
                # 最大値と一致で0以外の個数がk個になる
                dp[a][b][c] += dp[a-1][1][k] * (1 if digit == 0 else 0)
                dp[a][b][c] += dp[a-1][1][k-1] * (1 if digit != 0 else 0)
            elif b == 1 and c != k:
                dp[a][b][c] += dp[a-1][1][c] * (1 if digit == 0 else 0)
                dp[a][b][c] += 0 if c == 0 else dp[a-1][1][c-1] * (1 if digit != 0 else 0)
            else:
                None
#     print("--", a)
#     for i in range(k + 1):
#         print(dp[a][0][i])
#     for i in range(k + 1):
#         print(dp[a][1][i])

print(dp[keta][0][k] + dp[keta][1][k])


