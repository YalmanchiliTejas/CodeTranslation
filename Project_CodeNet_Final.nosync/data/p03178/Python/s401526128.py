mod=10**9+7
k=input()
d=int(input())
l=[int(i) for i in "0"+k]
dp=[[[0]*(d+2),[0]*(d+2)] for _ in "ww"]
dp[0][0][0]=1
#dp[1][1][0]=1
for i,j in enumerate(l):
    if i==0: continue
    for p in range(d+1):
        if dp[i%2-1][0][p]:
            dp[i%2][0][[(p+j)%d,d][(p+j)%d==0]]=1
            for q in range(j):
                dp[i%2][1][[[(p+q)%d,d][(p+q)%d==0],0][p==q==0]]+=1
        if dp[i%2-1][1][p]:
            for q in range(10):
                dp[i%2][1][[[(p+q)%d,d][(p+q)%d==0],0][p==q==0]]+=dp[i%2-1][1][p]
    for p in range(d+2):
        dp[i%2-1][0][p]=0
        dp[i%2-1][1][p]=0
        dp[i%2][0][p]%=mod
        dp[i%2][1][p]%=mod

print((dp[0][0][d]+dp[0][1][d]+dp[1][0][d]+dp[1][1][d])%mod)