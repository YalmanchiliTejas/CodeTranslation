N_string = input()
l = len(N_string)
N = int(N_string)
K = int(input())

n = int(N_string[0])
dp0 = [[n - 1, 0, 0]]
dp1 = [[1, 0, 0]]

for i in range(l - 1):
    n = int(N_string[i + 1])
    if n == 0:
        dp0.append([9 + dp0[i][0],
                    dp0[i][0] * 9 + dp0[i][1],
                    dp0[i][1] * 9 + dp0[i][2]])
        dp1.append([dp1[i][0], dp1[i][1], dp1[i][2]])
    else:
        dp0.append([9 + dp0[i][0] + dp1[i][0],
                    dp0[i][0] * 9 + dp0[i][1] + dp1[i][0] * (n - 1) + dp1[i][1],
                    dp0[i][1] * 9 + dp0[i][2] + dp1[i][1] * (n - 1) + dp1[i][2]])
        dp1.append([0, dp1[i][0], dp1[i][1]])
print(dp0[-1][K - 1] + dp1[-1][K - 1])