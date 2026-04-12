n, k = map(int, input().split())

if k == 0:
    ans = n ** 2
else:
    ans = 0
    for x in range(k + 1, n + 1):
        w = x - k
        u = n // x
        ans += w * u
        ans += max(n - (u * x + k - 1), 0)
print(ans)
