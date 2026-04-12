import sys
#input = sys.stdin.buffer.readline

def main():
    K = input()
    D = int(input())
    MOD = 10**9+7
    
    dp = [[0]*D for _ in range(2)]
    dp[1][0] = 1
    n = 0
    for st in K:
        num = int(st)
        n += num
        use = [0]*D
        for i in range(D):
            for j in range(10):
                use[(i+j)%D] += dp[0][i]
            if num != 0:
                for j in range(num):
                    use[(i+j)%D] += dp[1][i]
        dp[0] = use
        for i in range(D):
            dp[0][i] %= MOD
        dp[1] = [0]*D
        dp[1][n%D] += 1
    
    print((dp[0][0]+dp[1][0]-1)%MOD)

if __name__ == "__main__":
    main()
