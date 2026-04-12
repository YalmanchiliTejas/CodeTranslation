N, K = map(int, input().split())

ans = 0
k = K + 1
for i in range(1, N-K+1):
    ans += i * (N // k) + max(N % k - (K - 1), 0)
    k += 1

if K == 0:
    ans = N ** 2
print(ans)