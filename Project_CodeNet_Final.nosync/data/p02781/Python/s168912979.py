"""
桁DPで解ける
dp[i][j][k][l] => i桁目まで見る。i桁目がjであるような数字の数。kは0でない数の個数のメモ。lは未満フラグ。
"""
N = input()
K = int(input())
dp = [[[[0]*(2) for _ in range(5)]for _ in range(10)]for _ in range(len(N))]

#初期化
x = int(N[0])
for i in range(x+1):
    if i == 0:
        dp[0][i][0][1] += 1
    else:
        if i<x:
            flag = 1
        else:
            flag = 0
        dp[0][i][1][flag] += 1

for i in range(len(N)-1):
    x = int(N[i+1])
    for j in range(10):
        for k in range(4):
            for l in range(2):
                if l:
                    r = 10
                else:
                    r = x+1
                for m in range(r):
                    if l==0 and m==x:
                        flag = 0
                    else:
                        flag = 1
                    
                    if m == 0:
                        cnt = k
                    else:
                        cnt = k+1
                    dp[i+1][m][cnt][flag] += dp[i][j][k][l]

ans = 0
for j in range(10):
    ans += sum(dp[-1][j][K])

print(ans)