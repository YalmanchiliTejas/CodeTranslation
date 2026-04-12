n, k = map(int, input().split())
ans = 0
if k == 0:
    ans = n ** 2
else:
    for b in range(k + 1, n + 1):
        period = n // b
        nokori = n % b
        ans += period * (b - k) + max(nokori - k + 1, 0)
print(ans)
