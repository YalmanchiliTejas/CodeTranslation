n = int(input())
N = len(str(n))
k = int(input())
s = [int(i) for i in str(n)]
dpi = [[0]*(k+1) for _ in range(N+1)]
dpj = [[0]*(k+1) for _ in range(N+1)]
dpi[0][0] = 1
for i in range(N):
    for j in range(k+1):
        dpi[i+1][j] += dpi[i][j]*(s[i]==0)
        dpj[i+1][j] += dpj[i][j]+dpi[i][j]*(s[i]>0)
        if j < k:
            dpi[i+1][j+1]+=dpi[i][j]*(s[i]>0)
            dpj[i+1][j+1]+=dpj[i][j]*9+dpi[i][j]*max(0,s[i]-1)
print(dpi[N][k]+dpj[N][k])