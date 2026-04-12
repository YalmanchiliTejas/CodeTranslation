import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


k = input()
n = len(k)
d = int(input())
dp0 = [[0]*(d) for _ in range(n+1)]
dp1 = [[0]*(d) for _ in range(n+1)]
dp1[0][0] = 1
M = 10**9+7
for i in range(1,n+1):
    for j in range(d):
        v = int(k[i-1])
        dp1[i][j] = dp1[i-1][(j-v)%d]
        for vv in range(10):
            if vv<v:
                dp0[i][j] += dp1[i-1][(j-vv)%d]
            dp0[i][j] += dp0[i-1][(j-vv)%d]
        dp1[i][j] %= M
        dp0[i][j] %= M
ans = (dp0[n][0]+dp1[n][0]-1) % M
print(ans)