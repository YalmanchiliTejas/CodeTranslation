# 数字の文字列s
s = input()

# 非0桁の数
not_zero = int(input())

# 桁数
n = len(s)

# dp[決定済み桁数][未満フラグ][非0の桁数]
# 決定済み桁数: 0～n  今回の問題は 1<n<10の100乗 のため、nが最大100桁で多めに105桁を取る。
# 未満フラグ: 0:そこまでの桁がnと一致  1:そこまでの桁がnより小さい
# 非0の桁数: 0～k  1<=k<=3のため、多めに4を取る。
dp = [[[0] * 4 for i in range(2)] for j in range(105)]

# 初期化 空集合を作成
dp[0][0][0] = 1

for i in range(n):
    for j in range(2):
        for k in range(4):
            nd = int(s[i])
            for d in range(10):
                # 配る先
                ni = i + 1
                nj = j
                nk = k

                # 現在の桁が0でなければ、0の桁が一つ増えるため、配る先はnk += 1
                if d != 0:
                    nk += 1
                # 0の桁が指定より多い場合、配るのをやめる
                if nk > not_zero:
                    continue
                # 今までの桁と一致する場合
                if j == 0:
                    # 今までの桁が一致し、現在の桁がnの該当桁より大きい場合、配るのをやめる
                    if d > nd:
                        continue
                    # 今までの桁が一致し、現在の桁がnの該当桁より小さい場合、n未満に配る
                    if d < nd:
                        nj = 1
                dp[ni][nj][nk] += dp[i][j][k]

print(dp[n][0][not_zero] + dp[n][1][not_zero])
