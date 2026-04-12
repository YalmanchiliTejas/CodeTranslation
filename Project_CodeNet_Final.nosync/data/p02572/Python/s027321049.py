def main():
    n = int(input())
    A = [int(e) for e in input().split()]
    mod = 10 ** 9 + 7

    sa = sum(A)
    ans = 0
    for i in range(n):
        sa -= A[i]
        ans += A[i] * sa % mod

    ans %= mod
    print(ans)


if __name__ == '__main__':
    main()
