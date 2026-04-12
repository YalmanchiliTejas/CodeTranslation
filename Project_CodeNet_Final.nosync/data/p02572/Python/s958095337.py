def main():
    import sys
    readline = sys.stdin.readline

    mod = 10**9 + 7

    n = int(readline())
    A = list(map(int, readline().split()))

    sumA = sum(A) % mod
    ans = 0

    for i in A:
        sumA -= i
        ans += i * sumA
        ans %= mod

    ans %= mod
    print(ans)


if __name__ == '__main__':
    main()