mod=998244353
n,s=map(int,input().split())
a=list(map(int,input().split()))

dp=[[0]*(s+1) for _ in range(n)]

if a[0]<=s: dp[0][a[0]]=1

for i in range(1,n):
    for k in range(s+1):
        dp[i][k]=dp[i-1][k]
        if k-a[i]>0: dp[i][k]+=dp[i-1][k-a[i]]
        if a[i]==k: dp[i][k]+=i+1
        dp[i][k]%=mod

ans=0
for i in range(n):
    ans+=dp[i][s]
    ans%=mod
print(ans)