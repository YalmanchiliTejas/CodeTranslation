N, K = map(int, input().split())
ans = 0
for i in range(K+1, N+1):
    ans += (N // i)*(i - K) + max(0, (N % i - max(0, (K - 1))))
print(ans)
