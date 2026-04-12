#!python3

INF = -(10 ** 17)

# input
N = int(input())
A = list(map(int, input().split()))


def main():
    if N % 2 == 0:
        dp = [[INF] * 2 for _ in range(N)]
        dp[0][0] = A[0]
        dp[1][1] = A[1]
        for i in range(2, N):
            dp[i][0] = dp[i - 2][0] + A[i]
            if i > 2:
                dp[i][1] = max(dp[i - 2][1] + A[i], dp[i - 3][0] + A[i])
        
        ans = max(dp[-1][1], dp[-2][0])
        print(ans)
    else:
        dp = [[INF] * 3 for _ in range(N)]
        dp[0][0] = A[0]
        dp[1][1] = A[1]
        dp[2][0] = A[0] + A[2]
        dp[2][2] = A[2]
        for i in range(3, N):
            dp[i][0] = dp[i - 2][0] + A[i]
            dp[i][1] = max(dp[i - 2][1] + A[i], dp[i - 3][0] + A[i])
            if i > 3:
                a = dp[i - 2][2] + A[i]
                b = dp[i - 3][1] + A[i]
                c = dp[i - 4][0] + A[i]
                dp[i][2] = max(a, b, c)
        
        ans = max(dp[-1][2], dp[-2][1], dp[-3][0])
        print(ans)


if __name__ == "__main__":
    main()
