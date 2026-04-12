N = list(input())
K = int(input())

N.reverse()
n = [0]*100
for i in range(100):
    if 99-i < len(N):
        n[i] = int(N[99-i])

dp2 = [[0]*100 for _ in range(4)]
if n[0] == 0:
    dp2[0][0] = 1
else:
    dp2[1][0] = 1
for i in range(1,100):
    if n[i] == 0:
        for j in range(4):
            dp2[j][i] = dp2[j][i-1]
    else:
        for j in range(1,4):
            dp2[j][i] = dp2[j-1][i-1]

dp1 = [[0]*100 for _ in range(4)]
if n[0] != 0:
    dp1[0][0] = 1
    dp1[1][0] = n[0]-1
for i in range(4):
    for j in range(1,100):
        if i != 0:
            if n[j] != 0:
                dp1[i][j] = dp1[i-1][j-1]*9 + dp1[i][j-1]*1 + dp2[i-1][j-1]*max(0,n[j]-1) + dp2[i][j-1]*1
            else:
                dp1[i][j] = dp1[i-1][j-1]*9 + dp1[i][j-1]*1

        else:
            if n[j] != 0:
                dp1[i][j] = dp1[i][j-1]*1 + dp2[i][j-1]*1
            else:
                dp1[i][j] = dp1[i][j-1]*1

print(dp1[K][-1] + dp2[K][-1])