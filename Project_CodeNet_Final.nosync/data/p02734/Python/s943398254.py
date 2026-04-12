def main():
    mod=998244353
    n,s=map(int,input().split())
    a=list(map(int, input().split()))
    dp=[0]*(s+1)
    ans=0
    for i,x in enumerate(a):
        dp[0]+=1
        if x>s:
            continue
        ans=(ans+dp[s-x]*(n-i))%mod
        for k in range(s-1,x-1,-1):
            dp[k]=(dp[k]+dp[k-x])%mod
    print(ans)
    
if __name__ == '__main__':
    main()
