n = input()
km = int(input())
dp1 = [[0] * (4) for _ in range(len(n) + 1)]
dp2 = [[0] * (4) for _ in range(len(n) + 1)]
dp1[0][0] = 1
for i in range(len(n)):
    for j in range(4):
        # i+1桁目に0が入る場合
        if n[i] == '0':
            dp1[i + 1][j] += dp1[i][j]
            dp2[i + 1][j] += dp2[i][j]
        else:
            dp2[i + 1][j] += dp1[i][j]
            dp2[i + 1][j] += dp2[i][j]
        if j < 3:
            for k in range(1, ord(n[i]) - ord('0')):
                dp2[i + 1][j + 1] += dp1[i][j]
            if n[i] != '0':
                dp1[i + 1][j + 1] += dp1[i][j]
            for k in range(1, 10):
                dp2[i + 1][j + 1] += dp2[i][j]
print(dp1[len(n)][km] + dp2[len(n)][km])