def main():
    N = int(input())
    A = [int(n) for n in input().split()]

    M = 10 ** 9 + 7

    ans = 0
    cache = sum(A) % M
    for i in range(N-1):
        cache -= A[i]
        ans += A[i] * cache % M
    print(ans % M)


main()
