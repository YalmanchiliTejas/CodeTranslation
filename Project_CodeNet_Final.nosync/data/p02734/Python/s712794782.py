n,s=map(int,input().split())
a=list(map(int,input().split()))

dp=[0]*(s+1)
for i in range(n+1):
    dp[0]=1
ans=0

for i,w in enumerate(a):
    for j in range(s-w,-1,-1):
        dp[j+w]+=dp[j]
        dp[j+w]%=998244353
    ans+=dp[-1]
    ans%=998244353
    dp[0]+=1

print(ans)
