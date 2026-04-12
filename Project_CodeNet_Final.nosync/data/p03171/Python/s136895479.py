def main():
    n = int(input())
    a = list(map(int, input().split()))
    dp = [0] * (n*n)
    for i in range(n):
        dp[i+i*n] = a[i]
    for i in range(n - 2, -1, -1):
        for j in range(i + 1, n):
            dp[i+j*n] = max(a[i] - dp[i + 1+j*n], a[j] - dp[i+(j - 1)*n])
    print(dp[(n - 1)*n])
main()