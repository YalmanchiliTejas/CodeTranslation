N = int(input())
K = int(input())

Nstr = str(N)
Nlen = len(Nstr)

'''------dp設定-------
dp[i][j][k] 
dp[][][] 
i:桁数
j:非0の数を使った回数
k: 0:それまでの桁数は、Nと同じ
   1:それまでの桁数で、Nより小さいが確定
配るdpで更新
'''

#初期化
dp = [[[0 for i3 in range(2)] for i2 in range(K+1)] for i1 in range(Nlen+1)]
dp[0][0][0] = 1

#今の桁から次の桁に配るループ
for i in range(Nlen):
    for j in range(4):
        for k in range(2):
            nd = int(Nstr[i])
            for d in range(10):
                ni = i+1
                nj = j
                nk = k
                if d > 0:
                    nj += 1
                if nj > K:
                    continue
                if k == 0:
                    if d > nd:
                        continue
                    if d < nd:
                        nk = 1
                dp[ni][nj][nk] += dp[i][j][k]

print(dp[Nlen][K][0]+dp[Nlen][K][1])