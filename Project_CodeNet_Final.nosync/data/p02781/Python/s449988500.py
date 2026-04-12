N = int(input())
K = int(input())
L = len(str(N))
dp1 = [[0 for _ in range(K+1)] for _ in range(L+1)]
dp2 = [[0 for _ in range(K+1)] for _ in range(L+1)]
count = 0
for i in range(L+1):
    dp1[i][0] = 0
count = 0
for i, c in enumerate(str(N)):
    c = int(c)
    if i == 0:
        dp1[i+1][0] = 1
        dp1[i+1][1] = c-1
        dp2[i+1][1] = 1
        count = 1
        continue

    for j in range(0, K+1):
        if c == 0:
            dp2[i+1][j] += dp2[i][j]
        else:
            if j != K:
                dp2[i+1][j+1] += dp2[i][j]
    for j in range(0, K+1):
        if c != 0:
            dp1[i+1][j] += dp2[i][j]
        dp1[i+1][j] += dp1[i][j]


        if j != K:
            if count >= K:
                dp1[i+1][j+1] += dp2[i][j] * 9
                dp1[i+1][j+1] += dp1[i][j] * 9
            else:
                dp1[i+1][j+1] += dp2[i][j]*max(0, (c-1))
                dp1[i+1][j+1] += dp1[i][j]*9
    #print(dp1)
    #print(dp2)
print(dp1[-1][-1] + dp2[-1][-1])

