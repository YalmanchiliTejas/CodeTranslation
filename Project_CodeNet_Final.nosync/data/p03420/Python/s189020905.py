N, K = map(int, input().split())

if K == 0:
    print(N ** 2)
    exit()

ans = 0
for mod in range(1, N + 1):
    q, r = divmod(N, mod)
    ans += max(0, mod - K) * q + max(0, r - K + 1)
print(ans)
