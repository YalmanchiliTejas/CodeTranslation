mod = 1000000007
eps = 10**-9
inf = 10**20


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))
    if N == 2 or N == 3:
        print(max(A))
        exit()

    if N%2 == 0:
        dp = [[-inf] * 2 for _ in range(N+1)]
        dp[-1][0] = 0
        dp[0][1] = 0
        for i in range(N):
            dp[i+1][0] = dp[i-1][0] + A[i]
            dp[i+1][1] = max(dp[i-1][1], dp[i-2][0]) + A[i]
        print(max(dp[-1][1], dp[-2][0]))
        #print(dp)
    else:
        dp = [[-inf] * 3 for _ in range(N + 1)]
        dp[-1][0] = 0
        dp[0][1] = 0
        dp[1][2] = 0
        #print(dp)
        for i in range(N):
            dp[i + 1][0] = max(dp[i+1][0], dp[i - 1][0] + A[i])
            dp[i + 1][1] = max(dp[i+1][1], dp[i - 1][1]+A[i], dp[i - 2][0]+A[i])
            dp[i+1][2] = max(dp[i+1][2], dp[i-1][2]+A[i], dp[i-2][1]+A[i], dp[i-3][0]+A[i])
            dp[-1][0] = 0
            dp[0][1] = 0
            dp[1][2] = 0
            #print(dp)
        print(max(dp[-1][2], dp[-2][1], dp[-3][0]))
        #print(dp)


if __name__ == '__main__':
    main()
