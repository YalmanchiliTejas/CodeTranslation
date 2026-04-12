def resolve():
    n = int(input())
    a = list(map(int, input().split()))

    ans = 0
    mod = (10 ** 9) + 7
    csum = sum(a)

    for i in range(n):
        csum -= a[i]
        ans += a[i] * csum

    ans = int(ans % mod)
    print(ans)
 
resolve()
