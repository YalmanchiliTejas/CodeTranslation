N, K = map(int, input().split())

if K == 0:
    print(N * N)
    exit()

ans = 0
for b in range(K + 1, N + 1):
    ans += (N // b) * (b - 1 - K + 1)
    ans += max(N % b + 1 - K, 0)

print(ans)
