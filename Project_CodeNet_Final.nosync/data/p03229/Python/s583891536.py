n = int(input())
a = [int(input()) for _ in range(n)]
a.sort(reverse=True)

if n % 2 == 0:
    res = 0
    for i in range(n // 2 - 1):
        res += a[i] * 2
    res += a[n // 2 - 1]
    res -= a[n // 2]
    for i in range(n // 2 + 1, n):
        res -= a[i] * 2
    print(res)
else:
    res1 = 0
    for i in range(n // 2 - 1):
        res1 += a[i] * 2
    res1 += a[n // 2 - 1] + a[n // 2]
    for i in range(n // 2 + 1, n):
        res1 -= a[i] * 2

    res2 = 0
    for i in range(n // 2):
        res2 += a[i] * 2
    res2 -= a[n // 2] + a[n // 2 + 1]
    for i in range(n // 2 + 2, n):
        res2 -= a[i] * 2
    print(max(res1, res2))