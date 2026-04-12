N=int(input())
K=int(input())

string = str(N)
digits = len(string)

#dp[i][j][k]=と同じ桁数の整数で上からi桁目までで0でない数字がj個あるものの個数
#k=0: i桁目まで見てN未満が確定, k=1: 未確定
dp = [[[0]*2 for _ in range(K+1)] for __ in range(digits+1)]
#初期状態
dp[0][0][1] = 1

for i in range(digits):
    d = int(string[i])
    ni = i+1
    for j in range(K+1):
        for k in range(2):
            for nd in range(10):
                nk = 1 if k == 1 and nd == d else 0
                if k == 1 and nd > d: break

                nj = j + (1 if nd != 0 else 0)
                if nj > K: continue

                dp[ni][nj][nk] += dp[i][j][k]

print(dp[digits][K][0] + dp[digits][K][1])
