C = -(10**15 + 7)


def main():
    from collections import defaultdict
    N = int(input())
    K = N//2
    A = [int(i) for i in input().split()]
    dp = defaultdict(lambda: C)
    for i in range(N+1):
        dp[i, 0] = 0
        if i != 0:
            dp[(i, 1)] = max(dp[i-1, 1], A[i-1])
    for i in range(2, N+1):
        for j in range(i//2-1, (i+1)//2 + 1):
            if j < 0:
                continue
            # A_i(1-index)でj個選ばなければいけない
            dp[i, j] = max(dp[i, j], dp[i-2, j-1] + A[i-1],
                           dp[i-3, j-1] + A[i-1], dp[i-4, j-1] + A[i-1])
    print(max(dp[N, K], dp[N-1, K], dp[N-2, K]))
    # for i in range(N+1):
    #     for j in range(K+1):
    #         print("{:>4}".format(dp[i, j] if dp[i, j] != C else "C"),
    #               end=" " if j != K else "\n")


if __name__ == '__main__':
    main()
