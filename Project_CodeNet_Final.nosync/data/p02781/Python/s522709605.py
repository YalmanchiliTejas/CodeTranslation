n=input()
k=int(input())
dp=[[[0]*(k+1)for i in range(2)] for i in range(len(n)+1)]
dp[0][0][0]=1
for i in range(1,len(n)+1):
    for j in range(int(n[i-1])):
        if j==0:
            for h in range(k+1):
                dp[i][1][h]+=dp[i-1][0][h]
        else:
            for h in range(k):
                dp[i][1][h+1]+=dp[i-1][0][h]
    for j in range(10):
        if j==0:
            for h in range(k+1):
                dp[i][1][h]+=dp[i-1][1][h]
        else:
            for h in range(k):
                dp[i][1][h+1]+=dp[i-1][1][h]
    if int(n[i-1])==0:
        for h in range(k+1):
            dp[i][0][h]+=dp[i-1][0][h]
    else:
        for h in range(k):
            dp[i][0][h+1]+=dp[i-1][0][h]
print(dp[-1][0][-1]+dp[-1][1][-1])