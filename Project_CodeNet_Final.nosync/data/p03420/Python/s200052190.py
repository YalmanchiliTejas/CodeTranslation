N, K = map(int, input().split())
ans = 0
for b in range(K+1, N+1):
    q, r = divmod(N, b)
    ans += q * (b-K) + max(r - K + 1, 0)
    if K == 0:
        ans -= 1 #a != 0
    #print(ans)

print(ans)