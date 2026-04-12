def main():
    N = input()
    len_N = len(N)
    K = int(input())
    dp = [[[0] * (K+5) for _ in range(2)] for _ in range(len_N + 5)]
    dp[0][0][0] = 1
    for i in range(1,len_N+1):
        for smaller in range(2):
            for k in range(K+1):
                if smaller == 0:
                    for x in range(int(N[i-1])+1):
                        if int(N[i-1]) == x:
                            if x == 0:
                                dp[i][smaller][k] += dp[i-1][smaller][k]
                            else:
                                dp[i][smaller][k+1] += dp[i-1][smaller][k]
                        else:
                            if x == 0:
                                dp[i][1][k] += dp[i-1][smaller][k]
                            else:
                                dp[i][1][k+1] += dp[i-1][smaller][k]
                else:
                    for x in range(10):
                        if x == 0:
                            dp[i][smaller][k] += dp[i-1][smaller][k]
                        else:
                            dp[i][smaller][k+1] += dp[i-1][smaller][k]


    print(dp[len_N][0][K] + dp[len_N][1][K])







if __name__ == "__main__":
    main()