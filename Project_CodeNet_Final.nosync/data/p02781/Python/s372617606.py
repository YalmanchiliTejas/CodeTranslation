import sys
#input = sys.stdin.buffer.readline

def main():
    N = input()
    K = int(input())
    
    dp = [[0]*4 for _ in range(2)]
    dp[1][0] = 1
    
    for st in N:
        num = int(st)
        use = [[0]*4 for _ in range(2)]
        if num == 0:
            for i in range(4):
                use[0][i] += dp[0][i]
                use[1][i] += dp[1][i]
                if i != 3:
                    use[0][i+1] += dp[0][i]*9
        else:
            for i in range(4):
                use[0][i] += dp[0][i]+dp[1][i]
                if i != 3:
                    use[1][i+1] += dp[1][i]
                    use[0][i+1] += dp[0][i]*9
                    use[0][i+1] += dp[1][i]*(num-1)
        dp = use
    
    print(dp[0][K]+dp[1][K])

if __name__ == "__main__":
    main()
