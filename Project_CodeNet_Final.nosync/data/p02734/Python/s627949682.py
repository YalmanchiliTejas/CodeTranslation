N,S=map(int,input().split())
dp=[0]*3001
res=0
for i,a in enumerate(map(int,input().split())):
    for w in range(S-a,0,-1):
        dp[w+a]+=dp[w]
    dp[a]+=i+1
    res+=dp[S]
print(res%998244353)