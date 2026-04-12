MOD = int(1e9+7)


def main():
    N = int(input())
    A = list(map(int, input().split()))
    sm = 0
    for a in A:
        sm = (sm + a) % MOD
    ans = 0
    for a in A:
        ans += ((sm-a) % MOD)*a
        ans %= MOD
    if ans % 2 == 0:
        ans //= 2
    else:
        ans = (ans + MOD) // 2
    print(ans)


if __name__ == "__main__":
    main()
