def resolve():
    n = int(input())
    A = list(map(int, input().split()))
    sm = sum(A) % (10**9 + 7)

    ans = 0
    for a in A:
        sm -= a
        ans += sm * a
        ans %= (10**9 + 7)
    print(ans)

resolve()