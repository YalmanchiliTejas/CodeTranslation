n = int(input())
k = int(input())

digit = len(str(n))
# dp[i桁まで検査済み][coincidence][0以外の個数]
dp = [[[0] * (k + 1) for i in range(2)] for j in range(digit + 1)]

dp[0][1][0] = 1
for a in range(1, digit + 1):
    digitvalue = int(str(n)[a - 1])
    for c in range(k + 1):
        if c == k:
            # 最大値と不一致で0以外の個数がk個になる
            dp[a][0][c] += dp[a-1][0][k] * 1
            dp[a][0][c] += dp[a-1][0][k-1] * 9
            # d != 0(仮に3) -> 0
            # d == 0 -> 0にすると最大値と一致するのでだめ
            dp[a][0][c] += dp[a-1][1][k] * (1 if digitvalue != 0 else 0)
            # d != 0(仮に3) -> 1, 2(0はkにならないのでだめ、3はb == 1になるのでだめ)
            # d == 0 -> 0にするとkが増えないのでだめ
            dp[a][0][c] += dp[a-1][1][k-1] * (digitvalue - 1 if digitvalue != 0 else 0)
            # 最大値と一致で0以外の個数がk個になる
            dp[a][1][c] += dp[a-1][1][k] * (1 if digitvalue == 0 else 0)
            dp[a][1][c] += dp[a-1][1][k-1] * (1 if digitvalue != 0 else 0)
        elif c != k:
            # 最大値と不一致で0以外の個数がc個になる
            dp[a][0][c] += dp[a-1][0][c] * 1
            dp[a][0][c] += 0 if c == 0 else dp[a-1][0][c-1] * 9
            dp[a][0][c] += dp[a-1][1][c] * (1 if digitvalue != 0 else 0)
            dp[a][0][c] += 0 if c == 0 else dp[a-1][1][c-1] * (digitvalue - 1 if digitvalue != 0 else 0)
            dp[a][1][c] += dp[a - 1][1][c] * (1 if digitvalue == 0 else 0)
            dp[a][1][c] += 0 if c == 0 else dp[a - 1][1][c - 1] * (1 if digitvalue != 0 else 0)
        else:
            None
#     print("--", a)
#     for i in range(k + 1):
#         print(dp[a][0][i])
#     for i in range(k + 1):
#         print(dp[a][1][i])

print(dp[digit][0][k] + dp[digit][1][k])
