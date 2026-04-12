def main():
    import sys
    input = sys.stdin.readline
    
    N, X = map(int, input().split())
    
    dp = [[0,0] for i in range(N+1)]
    dp[0] = [1,1]
    for i in range(1,N+1):
        dp[i][0] = 2*dp[i-1][0] + 1
        dp[i][1] = 2*dp[i-1][1] + 3
    dp = dp[::-1]
    tmp = X
    i = 0
    j = 0
    ans = 0
    
    while tmp != 0:
        if tmp <= N - i:
            break
        if tmp < i - j + dp[i][1]:
            i += 1
        else:
            ans += dp[i][0]
            tmp -= (i - j + dp[i][1])
            if tmp >= 1:
                tmp -= 1
                ans += 1
                j = i
    print(ans)
            

main()