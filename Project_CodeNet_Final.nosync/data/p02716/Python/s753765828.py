def main():
    N=int(input())
    A=[int(_) for _ in input().split()]
    dp=[[0,0,0] for _ in range(N//2+1)]
    for i in range(N//2):
        dp[i+1][0]=dp[i][0]+A[i*2]
        dp[i+1][1]=max(dp[i][1],dp[i][0])+A[i*2+1]
        if N%2:
            dp[i+1][2]=max(dp[i][2],dp[i][1],dp[i][0])+A[i*2+2]
    if N%2:
        print(max(dp[-1]))
    else:
        print(max(dp[-1][:2]))

main()
