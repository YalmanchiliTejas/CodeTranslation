import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
def input(): return sys.stdin.readline().rstrip()

def main():
    N=int(input())
    K=int(input())
    str_N=str(N)
    M=len(str(N))
    dp=[[[0]*2 for _ in range(K+1)] for _ in range(M+1)]
    dp[0][0][0]=1
    for keta in range(M):
        dp[keta+1][0][1]=dp[keta][0][0]+dp[keta][0][1]
        for k in range(K):
            dp[keta+1][k+1][1]=dp[keta][k][0]*(max(int(str_N[keta])-1,0))+dp[keta][k][1]*9+dp[keta][k+1][1]
            if int(str_N[keta])==0:
                dp[keta+1][k+1][0]=dp[keta][k+1][0]
            else:
                dp[keta+1][k+1][0]=dp[keta][k][0]
                dp[keta+1][k+1][1]+=dp[keta][k+1][0]
    ans=sum(dp[M][K])
    print(ans)
                

if __name__ == '__main__':
    main()
