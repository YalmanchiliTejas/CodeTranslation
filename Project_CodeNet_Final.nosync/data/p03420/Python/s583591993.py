N, K = map(int, input().split())

ans = 0
for mod in range(1, N + 1):
    q, r = divmod(N, mod)
    ans += max(0, mod - K) * q + max(0, r - K + 1)
if K == 0:
    ans -= N
print(ans)
