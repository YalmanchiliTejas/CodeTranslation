def main():
    N = int(input())
    A = list(map(int, input().split()))
    mod = 7 + 10**9
    s = sum(A)
    s %= mod
    r = 0
    for i in range(N):
        s -= A[i]
        r += s * A[i]
        r %= mod
    return r
print(main())
