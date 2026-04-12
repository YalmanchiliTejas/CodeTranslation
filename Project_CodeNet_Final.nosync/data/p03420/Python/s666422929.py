n, k = map(int, input().split())
ans = 0
i = 0
if k == 0:
    ans = n ** 2
else:
    while i <= n:
        if i >= k:
            ans += n // (i + 1) * (i - k + 1)
        if k <= n % (i + 1) < n:
            ans += n % (i + 1) - (k - 1)
        i += 1
print(ans)
