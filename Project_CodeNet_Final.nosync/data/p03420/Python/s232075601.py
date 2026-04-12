n,k = map(int, input().split())
ans = 0
for p in range(k+1, n+1):
    if (n//p * p) + k <= n:
        ans += n - (n//p) * p - k + 1
    ans += n//p * (p-k)
if k == 0:
    ans -= n
print(ans)
