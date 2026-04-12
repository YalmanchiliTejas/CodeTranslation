def main():
    mod=998244353
    n,s=map(int,input().split())
    A=tuple(map(int,input().split()))
    DP=[[x+1]+[0]*s for x in range(n+1)]
    for i,a in enumerate(A):
        for j in range(1,s+1):
            if j-a<0:
                DP[i+1][j]=DP[i][j]
            else:
                DP[i+1][j]=DP[i][j]+DP[i][j-a]
            DP[i+1][j]%=mod
    ans=0
    for dp in DP:
        ans+=dp[-1]
        ans%=mod
    print(ans)
    
if __name__=='__main__':
    main()