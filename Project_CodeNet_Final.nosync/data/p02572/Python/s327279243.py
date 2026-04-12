def main():
    N = int(input())
    A = list(map(int, input().split()))

    mod = 10 ** 9 + 7

    s = [0] * N
    for i, a in enumerate(A[::-1], 1):
        if i == N:
            continue
        else:
            s[N-i-1] = (s[N-i] + a) % mod

    ans = 0
    for i, a in enumerate(A):
        ans += a * s[i]
        ans %= mod

    print(ans)


if __name__ == "__main__":
    main()
