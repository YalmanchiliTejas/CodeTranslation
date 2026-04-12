N = int(input())
K = int(input())

#桁DP
#dp0[i]: i桁目まで見てN未満が確定, dp1: 未確定
string = str(N)
digits = len(string)

#dp*[i][j]=i桁目まで見て0でない数字がK個あるようなものの個数
dp0 = [[0] * (K+1) for _ in range(digits+1)]
dp1 = [[0] * (K+1) for _ in range(digits+1)]

dp1[0][0] = 1

for i in range(digits):
    d = int(string[i])
    ni = i+1
    for j in range(K+1):
        for k in range(2):
            for nd in range(10):
                nj = j + (1 if nd != 0 else 0)
                if nj > K: continue
                nk = k
                if k == 1:
                    if nd < d: nk = 0
                    elif nd > d: continue
                dp_b = dp0 if k == 0 else dp1
                dp_a = dp0 if nk == 0 else dp1
                dp_a[ni][nj] += dp_b[i][j]

print(dp0[digits][K] + dp1[digits][K])
