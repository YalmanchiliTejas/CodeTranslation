n = input().strip()
k = int(input().strip())
le = len(n)
dp = [[[0] * 2 for _ in range(5)] for _ in range(101)]
dp[0][0][0] = 1

for i in range(le):
    for cnt in range(4):
        for smaller in range(2):
            fig = int(n[i])
            for d in range(10):
                tmp1 = i + 1
                tmp2 = cnt
                tmp3 = smaller
                if d != 0:
                    tmp2 += 1
                if k < cnt:
                    continue
                if smaller == 0:
                    if fig < d:
                        continue
                    elif d < fig:
                        tmp3 = 1
                dp[tmp1][tmp2][tmp3] += dp[i][cnt][smaller]
print(dp[le][k][0] + dp[le][k][1])
