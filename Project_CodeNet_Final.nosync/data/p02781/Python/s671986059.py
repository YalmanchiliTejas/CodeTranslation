n=int(input())
k=int(input())
l=[int(i) for i in "0"+str(n)]
# [0]=n [1]<n
dp=[[[0]*5,[0]*5] for i in "ww"]
dp[0][0][0]=1
for i,j in enumerate(str(n)):
    i+=1
    for p in range(k+1):
        if dp[i%2-1][0][p]:
            dp[i%2][0][p+[0,1][l[i]>0]]=1
            for q in range(l[i]):
                dp[i%2][1][p+[0,1][q>0]]+=1
        if dp[i%2-1][1][p]:
            dp[i%2][1][p]+=dp[i%2-1][1][p]
            dp[i%2][1][p+1]+=dp[i%2-1][1][p]*9
    for p in range(10): dp[i%2-1][p//5][p%5]=0
print(dp[0][0][k]+dp[1][0][k]+dp[0][1][k]+dp[1][1][k])
