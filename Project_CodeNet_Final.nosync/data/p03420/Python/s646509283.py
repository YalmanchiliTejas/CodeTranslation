n, k = map(int, input().split())
ans = 0
for b in range(k+1, n+1):
    ans += (n // b) * (b - k)
    ans += max(0, n % b - k + 1)
if k == 0:
    ans -= n
print(ans)
