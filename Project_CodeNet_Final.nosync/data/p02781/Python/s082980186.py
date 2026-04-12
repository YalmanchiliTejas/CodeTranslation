N = int(input())
K = int(input())
N = str(N)
dp = [[[0]*2 for _ in range(K+1)] for _ in range(len(N)+1)]
dp[0][0][1] = 1  # 初期化, まだ崩れていないという認識
# 遷移を考える
for i in range(len(N)):
    x = int(N[i])  # 上からi桁目を考える
    for j in range(K):
        # 崩れているものを増やしていく
        dp[i+1][j+1][0] += dp[i][j][0]*9  # 非ゼロを増やした
        dp[i+1][j][0] += dp[i][j][0]  # ゼロを使った
        # 崩れていないものについて
        if x > 0:
            dp[i+1][j][0] += dp[i][j][1]  # 0を使って崩す
            dp[i+1][j+1][0] += dp[i][j][1]*(x-1)  # x未満の数字を使って(jが増える)崩した場合
            dp[i+1][j+1][1] += dp[i][j][1]  # xをそのまま埋め込んで崩れていない状態を選んだ場合
        else:
            # 崩さない場合は、0を埋め込むしかないのでjは増えない
            dp[i+1][j][1] += dp[i][j][1]  # 0を埋め込む
    dp[i+1][K][0] += dp[i][K][0]
    dp[i+1][K][not x>0] += dp[i][K][1]
print(sum(dp[len(N)][K]))
