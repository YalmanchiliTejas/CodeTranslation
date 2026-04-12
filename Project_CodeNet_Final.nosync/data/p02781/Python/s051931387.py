N = input()
K = int(input())

L = len(str(N))
N2 = list(str(N))
dp1 = [[0 for i in range(L+1)] for j in range(3+1)]
dp2 = [[0 for i in range(L+1)] for j in range(3+1)]
dp1[0]=[1]*(L+1)
temp = 0
for i in range(L):
    #print(temp)
    if (N2[i] != "0" and temp <= K-1):
        temp += 1
        dp2[min(temp,K)][i+1] += 1
    elif (N2[i] == "0" and dp2[min(temp,K)][i] == 1):
        dp2[min(temp,K)][i+1] += 1
#print(dp2)

dp1[1][1] = int(N2[0])-1
for i in range(1,K+1):
    for j in range(2,L+1):
        if (N2[j-1] != "0" and i == 1 ):
            dp1[i][j] += dp1[i-1][j-1]*9+dp1[i][j-1]+dp2[i][j-1]
        elif (N2[j-1] != "0" and i == 2):
            dp1[i][j] += dp1[i-1][j-1]*9+dp1[i][j-1]+dp2[i-1][j-1]*(int(N2[j-1])-1)+dp2[i][j-1]
        elif (N2[j-1] != "0" and i == 3):
            dp1[i][j] += dp1[i-1][j-1]*9+dp1[i][j-1]+dp2[i-1][j-1]*(int(N2[j-1])-1)+dp2[i][j-1]
        else:
            dp1[i][j] += dp1[i-1][j-1]*9+dp1[i][j-1]
#print(dp1)
print(dp1[K][-1]+dp2[K][-1])