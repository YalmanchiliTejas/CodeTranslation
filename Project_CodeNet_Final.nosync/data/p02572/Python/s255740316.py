def main():
    MOD = 10 ** 9 + 7

    N = int(input())
    *A, = map(int, input().split())

    ans = 0
    s = A[0]
    for i in range(1, N):
        ans = (ans + s * A[i]) % MOD
        s = (s + A[i]) % MOD
    print(ans)


if __name__ == '__main__':
    main()
