def main():
    N = input()
    len_N = len(N)
    K = int(input())
    dp = [[[0] * 2 for _ in range(K + 5)] for _ in range(len_N + 5)]
    dp[0][0][0] = 1
    for i in range(len_N):
        tmp = int(N[i])
        for j in range(K+1):
            # l : 1 => N より小さいことが確定 
            for l in range(2):
                for x in range(10):
                    if l == 0:
                        if x > tmp:
                            continue
                        elif x == tmp:
                            if x == 0:
                                dp[i+1][j][0] += dp[i][j][0]
                            else:
                                dp[i+1][j+1][0] += dp[i][j][0]
                        else:
                            if x == 0:
                                dp[i+1][j][1] += dp[i][j][0]
                            else:
                                dp[i+1][j+1][1] += dp[i][j][0]
                    if l == 1:
                        if x == 0:
                            dp[i+1][j][1] += dp[i][j][1]
                        else:
                            dp[i+1][j+1][1] += dp[i][j][1]
    
    print(dp[len_N][K][0] + dp[len_N][K][1])


        




if __name__ == "__main__":
    main()