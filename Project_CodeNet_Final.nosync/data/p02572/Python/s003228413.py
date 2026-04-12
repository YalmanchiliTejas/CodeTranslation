#!/usr/bin/env python3

mod = 10**9 + 7


def main():
    N = int(input())
    A = list(map(int, input().split()))
    Asum = [0] * N
    Asum[0] = A[N - 1]
    for i in range(1, N):
        Asum[i] = Asum[i - 1] + A[N - 1 - i]
    ans = 0
    for i in range(N - 1):
        ans += (A[i] * Asum[N - 2 - i]) % mod
        ans %= mod
    print(ans)


if __name__ == "__main__":
    main()
