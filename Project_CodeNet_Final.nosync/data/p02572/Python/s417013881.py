def main():
    MOD = 10**9 + 7
    n = int(input())
    a = list(map(int, input().split()))
    b = [v for v in a]
    for i in range(1, n):
        b[i] += b[i-1]
        b[i] %= MOD
    ans = 0
    for i in range(n-1):
        ans += a[i] * ((b[n-1] - b[i])%MOD)
        ans %= MOD
    print(ans % MOD)

if __name__ == "__main__":
    main()