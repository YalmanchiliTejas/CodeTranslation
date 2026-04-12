N=input()
K=int(input())
dp_0 = [[0]*(len(N)) for i in range(K+1)]
dp_1 = [[0]*(len(N)) for i in range(K+1)]
dp_0[0][0]=1
dp_0[1][0]=int(N[0])-1
dp_1[1][0]=1
for i in range(len(N)-1):
    for j in range(K+1):
        if j==K:
            dp_0[j][i+1] += dp_0[j][i]
        elif j==0:
            dp_0[j][i+1] =dp_0[j][i]
            dp_0[j+1][i+1] += dp_0[j][i]*9
        else:
            dp_0[j][i+1] += dp_0[j][i]
            dp_0[j+1][i+1] += dp_0[j][i]*9
        if j != K and N[i+1] != '0':
            dp_0[j+1][i+1] += (int(N[i+1])-1)*dp_1[j][i]
            dp_0[j][i+1] += dp_1[j][i]
            dp_1[j+1][i+1] = dp_1[j][i]
        elif N[i+1] =='0':
            dp_1[j][i+1] = dp_1[j][i]
        else:

            dp_0[j][i+1] += dp_1[j][i]

print(dp_0[K][len(N)-1]+dp_1[K][len(N)-1])