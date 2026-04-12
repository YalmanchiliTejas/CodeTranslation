def main():
    N = int(input())
    A = list(map(int, input().split()))
    S = sum(A)
    mod = 10**9 + 7
    r = 0
    for a in A:
        S -= a
        r = (r + S * a) % mod
    return r

print(main())
