MOD = 10**9 + 7


def main():
    N = int(input())
    A = [int(i) for i in input().split()]
    from itertools import accumulate
    S = list(accumulate([0] + A))
    ans = 0
    for i in range(N-1):
        ans += A[i] * (S[N] - S[i+1])
        ans %= MOD
    print(ans)


if __name__ == '__main__':
    main()
