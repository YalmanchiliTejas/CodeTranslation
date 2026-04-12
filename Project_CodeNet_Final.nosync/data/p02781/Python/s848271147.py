n = input()
k = int(input())

# dp[digit][smaller][used # of non-0]
# dp[i][j][l]
dp = [[[0 for _ in range(k+2)] for _ in range(2)] for _ in range(len(n)+1)]
dp[0][0][0]=1

for i in range(len(n)):
    nd = int(n[i])
    for j in [0, 1]:
        for l in range(k+1):
            for d in range(10):
                ni=i+1
                nj=j
                nl=l

                if d!=0:
                    nl+=1
                if nl>k:
                    continue
                if j==0: # equal to n
                    if d > nd:
                        continue
                    if d < nd:
                        nj=1 # smaller
                dp[ni][nj][nl] += dp[i][j][l]

print(dp[len(n)][0][k]+dp[len(n)][1][k])