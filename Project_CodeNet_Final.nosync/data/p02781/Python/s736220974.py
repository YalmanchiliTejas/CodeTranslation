n = input()
k = int(input())
l = len(n)
dp = [[[0]*(k+1) for i in range(2)] for j in range(l+1)]
d = []
for i in range(l):
    d.append(int(n[i]))
dp[1][0][0] = 0
dp[1][0][1] = 1
dp[1][1][0] = 1
dp[1][1][1] = d[0]-1

for i in range(l):
    for small in range(2):
        for j in range(k+1):
            if j==k:
                if small==0 and d[i]==0:
                    dp[i+1][small][j] += dp[i][small][j]
                else:
                    dp[i+1][1][j] += dp[i][small][j]
            else:
                a = 10 if small else d[i]+1
                for x in range(a):
                    z=j if x==0 else j+1
                    dp[i+1][small or x<d[i]][z] += dp[i][small][j]


print(dp[l][0][k]+dp[l][1][k])