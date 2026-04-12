N,K = map(int, input().split())
ans = 0
for b in range(K+1, N+1):
    a = ((N+1) // b) * (b - K) + max(0 , (N+1)%b - K)
    ans += a
print(ans if K != 0 else N ** 2 )