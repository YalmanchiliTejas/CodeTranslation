N, K = map(int,input().split())
ans = 0
for b in range(K+1,N+1):
    ans += (b-K)*(N//b)
    if N%b >= K:
        ans += N%b-K+1
    if K == 0:
        ans -= 1
print(ans)