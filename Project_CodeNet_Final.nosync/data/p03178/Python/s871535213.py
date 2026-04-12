k=input()
d=int(input())
l=len(k)
N=10**9 + 7
dp=[[[0]*2 for _ in range(d+5)] for i in range(l+5)]
prefs=[int(k[0])%d]
for i in range(1,l):
    prefs.append((prefs[i-1]+int(k[i]))%d)
for i in range(0,int(k[0])):
    dp[0][i%d][1]+=1
dp[0][int(k[0])%d][0]+=1
for i in range(1,l):
    for r in range(d):
        for dig in range(10):
            dp[i][r][1]=(dp[i][r][1]+dp[i-1][(r-dig+d)%d][1])%N
        for dig in range(0,int(k[i])):
            dp[i][r][1] = (dp[i][r][1] + dp[i - 1][(r - dig + d) % d][0]) % N
        if prefs[i]==r:
            dp[i][r][0]=(dp[i][r][0]+1)%N
print((dp[l-1][0][1]+dp[l-1][0][0]-1+N)%N)



