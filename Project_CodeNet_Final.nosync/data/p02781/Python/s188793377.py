n,K=input(),int(input())
m=len(n)

DP=[[[0]*(K+2) for _ in range(2)] for _ in range(m+1)]
DP[0][0][0]=1

for i in range(1,m+1):
    for flag in range(2):
        num=9 if flag else int(n[i-1])
        for j in range(K+1):
            for k in range(num+1):
                if k!=0:DP[i][flag or k<num][j+1] +=DP[i-1][flag][j]
                else:DP[i][flag or k<num][j] +=DP[i-1][flag][j]

print(DP[m][0][K]+DP[m][1][K])