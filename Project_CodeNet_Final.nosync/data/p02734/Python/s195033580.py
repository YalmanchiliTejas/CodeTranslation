def main():
    import sys
    input=sys.stdin.readline
    n,s=map(int,input().split())
    A=list(map(int,input().split()))
    mod=998244353
    dp=[[0]*(s+1) for _ in range(n+1)]
    dp[0][0]=1
    for i in range(1,n+1):
        for j in range(s+1):
            a=A[n-i]
            if j-a>0:
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-a])%mod
            elif j==a:
                dp[i][j]=(dp[i-1][j]+i)%mod
            else:
                dp[i][j]=dp[i-1][j]
    ans=0
    for i in range(1,n+1):
        a=A[i-1]
        if s>a:
            ans=(ans+dp[n-i][s-a]*i)%mod
        elif s==a:
            ans=(ans+(n-i+1)*i)%mod
    print(ans)
if __name__ == '__main__':
    main()