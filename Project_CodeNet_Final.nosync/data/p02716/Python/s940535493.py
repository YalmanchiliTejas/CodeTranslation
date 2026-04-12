def main():
    import sys
    input=sys.stdin.readline
    n=int(input())
    A=list(map(int,input().split()))
    A_=[0]*n
    for i in range(n):
        if i%2==0:
            A_[i]=A[i]
        else:
            A_[i]==0
    for i in range(n-1):
        A_[i+1]+=A_[i]
    dp=[0]*n
    dp[1]=max(A[0],A[1])
    for i in range(2,n):
        if i%2==0:
            dp[i]=max(dp[i-2]+A[i],dp[i-1])
        else:
            dp[i]=max(dp[i-2]+A[i],A_[i-1])
    print(dp[n-1])
if __name__ == '__main__':
    main()