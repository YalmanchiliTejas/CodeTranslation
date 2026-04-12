def resolve():
    n = int(input())
    a = list(map(int, input().split()))

    mod = 10 ** 9 + 7
    s = 0
    sq = 0
    for i in range(n):
        s += a[i]
        sq += (a[i]) ** 2
        s %= mod
        sq %= mod
    s2 = (s ** 2) % mod

    ans = s2 - sq
    if ans < 0:
        ans += mod

    divs = pow(2, mod-2, mod)

    print((ans*divs)%mod)

resolve()