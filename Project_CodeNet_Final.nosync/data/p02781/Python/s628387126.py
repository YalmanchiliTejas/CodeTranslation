n = input()
k = int(input())
n_len = len(n)
dp0 = [[0]*k for i in range(n_len)]
dp1 = [[0]*k for i in range(n_len)]
for i in range(k):
    if i == 0:
        dp0[0][i]=int(n[0])-1
        dp1[0][i]=1
    else:
        dp0[0][i]=0
        dp1[0][i]=0

for i in range(1,n_len):
    for j in range(k):
        if j == 0:
            dp0[i][j]=9 + dp0[i-1][0] + dp1[i-1][0]*min(1,int(n[i]))
            dp1[i][j]=dp1[i-1][0] if int(n[i]) == 0 else 0
        else:
            dp0[i][j]=dp0[i-1][j-1]*9 + dp1[i-1][j-1]*max(0,int(n[i])-1) + dp0[i-1][j] + dp1[i-1][j]*min(1,int(n[i]))
            dp1[i][j]=dp1[i-1][j-1] if int(n[i]) != 0 else dp1[i-1][j]
            
print(dp0[n_len-1][k-1]+dp1[n_len-1][k-1])