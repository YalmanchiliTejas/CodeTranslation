n = list(map(int, list(input())))
k = int(input())

digits = len(n)

dp_le = [[0 for j in range(k+1)] for i in range(digits)]
dp_lt = [[0 for j in range(k+1)] for i in range(digits)]

dp_le[0][0] = 0
dp_le[0][1] = 1
dp_lt[0][0] = 1
dp_lt[0][1] = n[0]-1

for i in range(1, digits):
    for j in range(k+1):
        if n[i] == 0:
            dp_le[i][j] = dp_le[i-1][j]
            dp_lt[i][j] = dp_lt[i-1][j]
            if j > 0:
                dp_lt[i][j] += dp_lt[i-1][j-1]*9
        else:
            dp_lt[i][j] = dp_lt[i-1][j] + dp_le[i-1][j]
            if j > 0:
                dp_le[i][j] += dp_le[i-1][j-1]
                dp_lt[i][j] += dp_lt[i-1][j-1]*9 + dp_le[i-1][j-1] * (n[i] - 1)

print(dp_le[digits-1][k] + dp_lt[digits-1][k])
