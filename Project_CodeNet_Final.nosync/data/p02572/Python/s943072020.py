def resolve():
    n = int(input())
    a = list(map(int, input().split()))

    mod = 10**9+7
    s = 0
    sq = 0
    for i in range(n):
        s += a[i]
        sq += (a[i])**2

    print(((s**2-sq)//2)%mod)

resolve()