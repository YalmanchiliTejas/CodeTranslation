
#dp[i][k] : i番目まで見て、0でない数がk個出現しているときの組合せ
#dp0[][] : N以下であるか未確定、dp1[][] = N以下が確定

#例:1以上N以下の整数であって、0でない数字がちょうどK個あるような個数

def main(N,K):
    dp0 = [[0] * (K + 1) for _ in range(len(N) + 1)]
    dp1 = [[0] * (K + 1) for _ in range(len(N) + 1)]
    dp0[0][0] = 1

    #桁ごと(最上位桁から)
    for i, n in enumerate(N):
        for k in range(K + 1):
            #確認中の桁が0の場合
            if n == '0':
                dp0[i+1][k] += dp0[i][k]
                dp1[i+1][k] += dp1[i][k]
                #k < Kの場合
                if k < K:
                    dp1[i + 1][k + 1] += 9 * dp1[i][k]
            #確認中の桁が0以外の場合
            else:
                if k < K:
                    dp0[i+1][k+1] += dp0[i][k]
                    dp1[i+1][k+1] += (int(n) - 1) * dp0[i][k]
                    dp1[i+1][k+1] += 9 * dp1[i][k]

                dp1[i+1][k] += dp0[i][k]
                dp1[i+1][k] += dp1[i][k]
    print(dp0[-1][K] + dp1[-1][K])

N = input()
K = int(input())
main(N,K)
