MOD = 10**9 + 7


def main():
    _ = int(input())
    A = [int(i) for i in input().split()]

    ans = (sum(A)**2) % MOD - (sum(pow(a, 2, MOD) for a in A)) % MOD
    ans *= pow(2, MOD-2, MOD)
    ans %= MOD
    print(ans)


if __name__ == '__main__':
    main()
