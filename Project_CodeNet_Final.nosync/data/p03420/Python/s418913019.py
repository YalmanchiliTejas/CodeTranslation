N, K = map(int, input().split())
if K == 0:
    print(N * N)
    exit()
ans = 0
for i in range(N):
    if i < K:
        continue
    ans += (N // (i + 1)) * (i - K + 1) + max(N % (i + 1) - K + 1, 0)
print(ans)
