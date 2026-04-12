N = int(input())
K = int(input())

Nstr = str(N)

l = len(Nstr)

DP = [[[0]*2 for j in range(K+1)] for i in range(l+1)]

DP[0][0][1] = 1

for i in range(l):
    if int(Nstr[i])==0:
        for j in range(K+1):
            DP[i+1][j][0] += DP[i][j][0]
            DP[i+1][j][1] += DP[i][j][1]
            if j>0:
                DP[i+1][j][0] += 9*DP[i][j-1][0]
    else:
        for j in range(K+1):
            DP[i+1][j][0] += DP[i][j][0]+DP[i][j][1]
            if j>0:
                DP[i+1][j][0] += (int(Nstr[i])-1)*DP[i][j-1][1]+9*DP[i][j-1][0]
                DP[i+1][j][1] += DP[i][j-1][1]

print(DP[l][K][0] + DP[l][K][1])        