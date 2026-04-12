N, K = map(int, input().split())

ans = 0
for b in range(K + 1, N + 1):
    ans += (b - K) * (N // b)
    if N % b != 0:
        if K != 0:
            ans += max(0, N - N // b * b - K + 1)
        else:
            ans += max(0, N - N // b * b - K)

print(ans)