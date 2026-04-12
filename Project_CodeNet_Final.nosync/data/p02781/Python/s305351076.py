n = int(input())
k = int(input())

dp = [[[0]*(2) for i in range(k+1)] for j in range(len(str(n))+1)]

dp[0][0][0] = 1

for i in range(len(str(n))):
    for j in range(k+1):
        for m in range(2):
            nd = int(str(n)[i])
            for l in range(10):
                ni = i+1
                nj = j
                nm = m
                if l != 0:
                    nj += 1
                if nj > k:
                    continue
                if nm == 0:
                    if  l > nd:
                        continue
                    elif l < nd:
                        nm = 1
                dp[ni][nj][nm] += dp[i][j][m]
print(dp[len(str(n))][k][0]+dp[len(str(n))][k][1])