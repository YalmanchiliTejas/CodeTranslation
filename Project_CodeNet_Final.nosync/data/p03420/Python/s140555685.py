N, K = map(int, input().split())

ans = 0
for b in range(K+1, N+1):
    ans += N//b*(b-K)
    ans += max(N-N//b*b-max(K-1, 0), 0)

print(ans)