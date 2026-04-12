N, K = map(int, input().split())
ans = 0
for b in range(K+1, N+1):
    k = N // b
    ans += k * (b-K) + max((N % b) - K + 1, 0)
    if K == 0:
        ans -= 1
print(ans)