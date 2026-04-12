N, K = map(int, input().split())

ans = 0
for b in range(K + 1, N + 1):
    p = N // b
    q = p * (b - K) + max(N % b - K + 1, 0)
    ans += q if K > 0 else q-1

print(ans)
