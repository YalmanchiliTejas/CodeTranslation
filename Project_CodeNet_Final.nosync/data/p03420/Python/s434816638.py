def solve():
    N, K = map(int, input().split())
    ans = 0
    if K == 0: print(N ** 2)
    else:
        for b in range(K + 1, N + 1):
            a = N // b
            ans += a * (b - K)
            ans += max(0, N - (a * b + K) + 1)
            
        print(ans)

    return 0

if __name__ == "__main__":
    solve()