N,K = map(int,input().split())
ans = 0
for b in range(K+1,N+1):
    ans += (b-K)*(int(N//b))
    last = int(N//b)
    if b*last + K <= N:
        ans += N- (b*last+K) +1
    if K == 0:
        ans -= 1
print(ans)