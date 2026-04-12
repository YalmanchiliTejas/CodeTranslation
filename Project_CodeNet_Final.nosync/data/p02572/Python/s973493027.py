def main():
    MOD = 10 ** 9 + 7
    N = int(input())
    A = list(map(int, input().split()))
    cs = [0] * N
    cs[0] = A[0]
    for i in range(1, N):
        cs[i] = cs[i - 1] + A[i]
        cs[i] %= MOD
    ans = 0
    for i in range(1, N):
        ans += A[i] * cs[i - 1]
        ans %= MOD
    print(ans)


if __name__ == '__main__':
    main()