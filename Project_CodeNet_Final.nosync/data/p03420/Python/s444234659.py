n, k = map(int, input().split())
ans = 0
for b in range(1, n + 1):
    ans += ((n // b) * max(0, b - k)) + max(0, (n % b) - k + 1)
if k == 0:
    ans = n ** 2
print(ans)
