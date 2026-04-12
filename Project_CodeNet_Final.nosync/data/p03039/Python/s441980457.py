import sys
from itertools import combinations

def comb_mod(n, r, MOD=10**9+7):
    if n < 0 or r < 0 or n < r:
        return 0

    factrial = [1] * (n+1)
    for k in range(1, n+1):
        factrial[k] = (factrial[k-1] * k) % MOD

    fact_inv = [1] * (n+1)
    fact_inv[n] = pow(factrial[n], MOD - 2, MOD)
    for k in range(n-1, -1, -1):
        fact_inv[k] = (fact_inv[k+1] * (k+1)) % MOD

    return (factrial[n] * fact_inv[r] * fact_inv[n-r]) % MOD


def main():
    input = sys.stdin.readline
    MOD = 10**9 + 7
    N, M, K = map(int, input().split())

    # The number of times that pieces are located on certain two tiles.
    num = comb_mod(N*M-2, K-2)

    ans = 0
    # Column-wise distance
    for i in range(M):
        ans += i * (M - i) * N**2 * num
        ans %= MOD

    # Row-wise distance
    for i in range(N):
        ans += i * (N - i) * M**2 * num
        ans %= MOD

    return ans


if __name__ == '__main__':
    print(main())
