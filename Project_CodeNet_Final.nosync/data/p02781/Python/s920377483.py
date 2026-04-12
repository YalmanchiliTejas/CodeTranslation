n = input().rstrip()
m = int(input())

dp = [[[0 for _ in range(2)] for _ in range(4)] for _ in range(101)]
dp[0][0][0] = 1

for i in range(len(n)):
    for j in range(4):
        for k in range(2):
            nd = ord(n[i]) - ord('0')
            for d in range(10):
                ni = i + 1
                nj = j
                nk = k
                if d != 0:
                    nj += 1
                if nj > m:
                    continue
                if k == 0:
                    if d > nd:
                        continue
                    if d < nd:
                        nk = 1
                dp[ni][nj][nk] += dp[i][j][k]
            
print(dp[len(n)][m][0] + dp[len(n)][m][1])
