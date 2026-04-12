n = input()
k = int(input())
keta = len(n)
ans = 0


dp = [[[0] * 2 for i in range(4)] for i in range(keta + 1)]
dp[0][0][0] = 1

for i in range(keta):
    # 同じ -> 同じ
    if n[i] == "0":
        for j in range(4):
            dp[i + 1][j][0] += dp[i][j][0]
    else:
        for j in range(3):
            dp[i + 1][j + 1][0] += dp[i][j][0]
    
    # 同じ -> 違う
    for ii in range(int(n[i])):
        if ii == 0:
            for j in range(4):
                dp[i + 1][j][1] += dp[i][j][0]
        else:
            for j in range(3):
                dp[i + 1][j + 1][1] += dp[i][j][0]
    # 違う -> 違う
    for ii in range(10):
        if ii == 0:
            for j in range(4):
                dp[i + 1][j][1] += dp[i][j][1]
        else:
            for j in range(3):
                dp[i + 1][j + 1][1] += dp[i][j][1]
print(sum(dp[keta][k]))