
n = list(map(int, list(input())))
k = int(input())
l = len(n)
dp0 = [[0]*(k+1) for _ in range(l+1)] #小さいの確定
dp1 = [[0]*(k+1) for _ in range(l+1)]

for i in range(1, l+1):
    dp0[i][0] = 1

dp1[0][0] = 1

for i in range(l):
    for j in range(k):

        if n[i] > 0:

            dp0[i+1][j+1] = \
                9*dp0[i][j] + dp0[i][j+1] + dp1[i][j+1] + (n[i]-1)*dp1[i][j]
            dp1[i + 1][j + 1] = dp1[i][j]
        else:

            dp0[i+1][j+1] = \
                9*dp0[i][j] + dp0[i][j+1]
            dp1[i + 1][j + 1] = dp1[i][j + 1]



# print(dp1[l][k])
print(dp0[l][k] + dp1[l][k])
