nl = list(input())
k = int(input())
l = len(nl) - k

# iけためまでの0のj数
dp1 = [[0 for i in range(l+2)] for j in range(len(nl)+1)]
dp2 = [[0 for i in range(l+2)] for j in range(len(nl)+1)]
dp1[0][0] = 0
dp2[0][0] = 1
for i, t in enumerate(nl):
    t = int(t)
    for j in range(10):
        if j == 0:
            if j < t:
                for p in range(l+1):
                    dp1[i+1][p+1] += dp2[i][p]
                    dp1[i+1][p+1] += dp1[i][p]
            elif j == t:
                for p in range(l+1):
                    dp2[i+1][p+1] += dp2[i][p]
                    dp1[i+1][p+1] += dp1[i][p]
            else:
                for p in range(l+1):
                    dp1[i+1][p+1] += dp1[i][p]
        else:
            if j < t:
                for p in range(l+1):
                    dp1[i+1][p] += dp2[i][p]
                    dp1[i+1][p] += dp1[i][p]
            elif j == t:
                for p in range(l+1):
                    dp2[i+1][p] += dp2[i][p]
                    dp1[i+1][p] += dp1[i][p]
            else:
                for p in range(l+1):
                    dp1[i+1][p] += dp1[i][p]


print(dp1[-1][l] + dp2[-1][l])

