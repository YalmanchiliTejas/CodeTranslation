import math
N = int(input())
K = int(input())
# keta → 10 なら 2
S = str(N)
keta = len(S)


dp1 = [ [ 0 ]* (keta + 1)  for _ in range(100) ] #超えないことが確定した方
dp2 = [  [ 0 ]* (keta + 1)  for _ in range(100) ] # 超える可能性がある方
# dp[以下確定済みフラグ][0でないの個数 k ][上からn桁目か] の条件を満たしたものの個数

i = int(S[0])
dp2[0][0] = 1 #超える可能性はある

for n in  range(0,keta):
    # for i in range(0,10): #次の桁に来る候補  #ここを省略して 1～9 と 0で場合分け
    for k in range(0, K + 1):
        num = int(S[n])  #実際の数字
        num_to_9  = 9 - num  # 5 だったら 6,7,8,9
        num_hiku1_to_1 = max(0,num - 1) #未満が確定する 0 以外の数
        # 確定から確定
        #確定済みには何をつけても良い

        if num == 0:
            dp1[k + 1][n + 1] += dp1[k][n] * 9 # 1~ 9
            dp1[k][n + 1] += dp1[k][n] # 0を足して確定
            # dp1[k][n + 1] += dp2[k][n]
            dp2[k][n + 1] += dp2[k][n] #0を足して未定パターン

        else:
            dp1[k + 1][n + 1] += dp1[k][n] * 9 # 1~ 9 を 超えないことが確定したやつに足したパターン
            dp1[k + 1][n + 1] += dp2[k][n] * (num - 1)  # 超えないやつを未定に足したパターン
            dp2[k + 1][n + 1] += dp2[k][n] #未定に引き続き未定になるやつを足したパターン

            # 0 を足すパターンがまだ
            dp1[k][n + 1] += dp1[k][n] # 超えないが確定したやつに0を足すパターン
            #  当然dp1に遷移

            dp1[k][n + 1] += dp2[k][n] # 超えるかもなやつに0を足すパターン
            # num > 0なのでdp2 からdp1に遷移
        # 未確定から未確定


print(dp1[K][keta] + dp2[K][keta])


