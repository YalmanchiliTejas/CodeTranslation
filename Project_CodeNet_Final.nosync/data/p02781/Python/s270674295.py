N = list(input())
K = int(input())

DP = [[[1,0,0,0,],[0,0,0,0]] for i in range(len(N)+1)]
for i in range(len(N)):
    if N[-1-i] == '0':
        for k in range(K):
            DP[i+1][0][k+1] = DP[i][0][k+1]
            DP[i+1][1][k+1] = DP[i][1][k+1]
    else:
        for k in range(K):
            DP[i+1][0][k+1] = DP[i][0][k+1]+DP[i][1][k+1]
    for j in range(1,10):
        for k in range(K):
            if j > int(N[-1-i]):
                DP[i+1][1][k+1] += DP[i][1][k] + DP[i][0][k]
            elif j < int(N[-1-i]):
                DP[i+1][0][k+1] += DP[i][1][k] + DP[i][0][k]
            elif j == int(N[-1-i]):
                DP[i+1][0][k+1] += DP[i][0][k]
                DP[i+1][1][k+1] += DP[i][1][k]
"""
for i in DP:
    for j in i:
        print(j)
    print()
"""
print(DP[-1][0][K]) 
