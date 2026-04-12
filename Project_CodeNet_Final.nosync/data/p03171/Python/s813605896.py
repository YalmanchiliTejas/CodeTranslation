def main():
    N = int(input())
    a = list(map(int, input().split()))

    dp = [0 for i in range(N)]

    for i in range(N-1, -1, -1):
        dp[i] = a[i]
        prev = dp[i]
        for j in range(i+1, N):
            right = a[i] - dp[j]
            left = a[j] - prev
            if right > left:
                dp[j] = right
                prev = right
            else:
                dp[j] = left
                prev = left
    print(dp[-1])


main()
