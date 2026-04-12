n = input()
k = int(input())


dp0 = [[0]*5 for i in range(len(n)+1)]
dp1 = [[0]*5 for i in range(len(n)+1)]

dp0[0][0] = 1


for i in range(1, len(n)+1):
    nn = int(n[i-1])
    for j in range(4):
        dp0[i][j] += dp0[i-1][j]*(nn==0)
        dp1[i][j] += dp1[i-1][j] + dp0[i-1][j]*(nn!=0)
        dp0[i][j+1] += dp0[i-1][j]*(nn!=0)
        dp1[i][j+1] += dp1[i-1][j]*9 + dp0[i-1][j]*(nn-1)*(nn!=0)

print(dp0[len(n)][k]+dp1[len(n)][k])