def solve():
    N = input()
    K = int(input())
    l = len(N)
    dp = [[[0]*(K+2) for i in range(2)] for j in range(l+1)]
    dp[0][False][0] = 1 

    for i in range(l):
        for smaller in [False,True]:
            for k in range(K+1):
                for x in range(10 if smaller else int(N[i])+1):
                    if x == 0:
                        dp[i+1][smaller or (x < int(N[i]))][k] += dp[i][smaller][k]
                    else:
                        dp[i+1][smaller or (x < int(N[i]))][k+1] += dp[i][smaller][k]
    
    print(dp[l][False][K] + dp[l][True][K])

if __name__ == '__main__':
    solve()