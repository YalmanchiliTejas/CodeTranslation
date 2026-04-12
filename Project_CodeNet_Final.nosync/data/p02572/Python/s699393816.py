def main():
    n = int(input())
    A = list(map(int, input().split()))
    p = 10**9 + 7
    ans = 0
    sumA = sum(A)

    for i, Ai in enumerate(A[:-1]):
        sumA -= Ai
        ans += Ai * sumA % p

    print(ans % p)


if __name__ == '__main__':
    main()
