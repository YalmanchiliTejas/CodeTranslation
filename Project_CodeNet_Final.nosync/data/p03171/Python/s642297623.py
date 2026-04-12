def solve():
    import sys
    input = sys.stdin.readline
    n=int(input())
    a=list(map(int,input().split()))
    dp=a[:]
    for i in range(1,n):
        for j in range(i-1,-1,-1):
            dp[j]=max(a[i]-dp[j],a[j]-dp[j+1])
    print(dp[0])
solve()