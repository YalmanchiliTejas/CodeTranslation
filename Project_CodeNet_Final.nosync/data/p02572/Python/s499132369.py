def main():
    N = int(input())
    A = list(map(int, input().split()))

    mod = 10**9 + 7

    tmp = [0] * N

    s = 0
    for i in range(N):
        tmp[- i - 1] = s
        s += A[-i - 1]

    # print(tmp)

    ans = 0
    for i in range(N):
        ans += A[i] * tmp[i]

    print(ans % mod)


if __name__ == '__main__':
    main()
