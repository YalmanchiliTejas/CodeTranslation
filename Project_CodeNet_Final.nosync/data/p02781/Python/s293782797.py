n = input()
k = int(input())
nl = len(n)#桁数
dp = [[[0] * (k + 1) for i in range(2)] for i in range(nl + 1)]
dp[0][0][0] = 1# 初期条件

# dp[i][j][k] i:桁数 j:smallフラグ 1はsmall確定、0はnと同じ値 k:ゼロ以外の数字を使った回数
for i in range(nl):
    for j in range(2):
        for l in range(k + 1): # lはK+1(つまりk)までの範囲にしても問題なし。下でl<kするから
            c = int(n[i])# 今調べている桁の数
            if j == 1:  # small確定の場合
                dp[i + 1][j][l] += dp[i][j][l]  # kの値が等しいので次の桁で0が来なければいけない
                if l < k:  # まだ0でない数の個数がkより少ない場合   ※比較する変数注意！
                    dp[i + 1][j][l + 1] += dp[i][j][l] * 9  # 次の桁で1~9を使う
            else:  # j==0のとき つまり現在まで調べている桁数の部分がnと一致している。
                if c == 0:
                    # cが0のときは0しか選べなく、small確定できない
                    dp[i + 1][0][l] += dp[i][j][l]
                else:
                    dp[i + 1][1][l] += dp[i][j][l]  # Cより小さい0を使う→small確定
                    if l < k: #※比較する変数注意！
                        dp[i + 1][1][l + 1] += dp[i][j][l] * (c - 1)  # c以外の数字を使う、small確定
                        dp[i + 1][0][l + 1] += dp[i][j][l]  # cを使う、small確定できない
print(dp[nl][1][k]+dp[nl][0][k])