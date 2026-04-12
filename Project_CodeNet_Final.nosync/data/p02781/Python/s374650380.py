str_n = input()
keta = len(str_n)
not_zero = int(input())

dp = [[[0]*(not_zero+2) for _ in range(2)] for _ in range(keta+1)]
first = int(str_n[0])
dp[1][1][0] = 1
for k in range(1,10):
    if first == k:
        dp[1][0][1] += 1
    elif first > k:
        dp[1][1][1] += 1

for i in range(1,keta):
    # smallerからsmallerへの遷移
    for j in range(not_zero+1):
        # i桁目をゼロにする
        dp[i+1][1][j] += dp[i][1][j]
        # i桁目でゼロ以外を使う
        dp[i+1][1][j+1] += (dp[i][1][j])*9

    nex = int(str_n[i])
    # sameからsmallerへの遷移
    if not nex == 0:
        for j in range(not_zero+1):
            # i桁目をぜろにする
            dp[i+1][1][j] += dp[i][0][j]
            # i桁目でゼロ以外
            dp[i+1][1][j+1] += (dp[i][0][j]) * (nex-1)
    
    # sameからsameへの遷移
    if nex == 0:
        for j in range(not_zero+1):
            dp[i+1][0][j] = dp[i][0][j]
    else:
        for j in range(not_zero):
            dp[i+1][0][j+1] = dp[i][0][j]

print(dp[keta][1][not_zero] + dp[keta][0][not_zero])



