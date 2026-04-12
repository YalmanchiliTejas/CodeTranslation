N, K = map(int, input().split())
ans = 0
for b in range(K + 1, N + 1):
    p, q = divmod(N, b)
    ans += p * (b - K)
    if K:
        ans += max(0, q - K + 1)
    else:
        ans += q
print(ans)