import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = input()
k = int(input())
l = len(n)
dp1 = [[0]*(k+1) for _ in range(l+1)]
dp0 = [[0]*(k+1) for _ in range(l+1)]
dp1[0][0] = 1
dp0[0][0] = 0
for i in range(1, l+1):
    for j in range(0, k+1):
        if n[i-1]=="0":
            dp1[i][j] = dp1[i-1][j]
        else:
            if j>=1:
                dp1[i][j] = dp1[i-1][j-1]
            dp0[i][j] += dp1[i-1][j]
        if int(n[i-1])>=2 and j>=1:
            dp0[i][j] += dp1[i-1][j-1] * (int(n[i-1])-1)
        if j>=1:
            dp0[i][j] += dp0[i-1][j-1]*9
        dp0[i][j] += dp0[i-1][j]
print(dp0[l][k]+dp1[l][k])