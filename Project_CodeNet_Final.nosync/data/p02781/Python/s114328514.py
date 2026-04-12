#

import sys
input=sys.stdin.readline

def main():
    N=input().strip("\n")
    K=int(input())
    # dp[i][j][k]=i桁目 j: nonzero数　k:N以下確定か
    dp=[[[0]*(2) for i in range(K+1)] for j in range(len(N))]
    dp[0][0][1]=1
    dp[0][1][1]=int(N[0])-1
    dp[0][1][0]=1
    for i in range(len(N)):
        dp[i][0][1]=1
    for i in range(1,len(N)):
        d=int(N[i])
        for j in range(1,K+1):
            if d!=0:
                dp[i][j][1]=dp[i-1][j-1][1]*9+dp[i-1][j-1][0]*(d-1)
                # nonzeroを使う場合i-1で既にN以下確定なら好き勝手できる*9
                
                dp[i][j][1]+=dp[i-1][j][1]+dp[i-1][j][0]
                # zeroを使う場合
                
                dp[i][j][0]=dp[i-1][j-1][0]
                # d未満とったら確定するため。
            else:
                dp[i][j][1]=dp[i-1][j-1][1]*9+dp[i-1][j][1]                
                dp[i][j][0]=dp[i-1][j][0]
    print(sum(dp[len(N)-1][K]))
    
        
    
if __name__=="__main__":
    main()
