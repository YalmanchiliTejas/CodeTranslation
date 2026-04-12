N, K = map(int, input().split())

ans = 0
if K == 0:
    ans = N * N
else:
    for b in range(1, N + 1):
        div, mod = divmod(N, b)
        ans += max(0, b - K) * div
        ans += max(0, mod - K + 1)

print(ans)
