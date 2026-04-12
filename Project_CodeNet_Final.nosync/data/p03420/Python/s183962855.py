N, K = map(int, input().split(" "))

ans = 0
for b in range(K + 1, N + 1):
    ans += (b - K) * (N // b) + max(0, N % b - K + 1)
    if K == 0:
        ans -= 1
print(ans)