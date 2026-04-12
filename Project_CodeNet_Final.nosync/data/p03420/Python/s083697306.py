N,K=map(int, input().split())

ans=0
for b in range(K+1,N+1):
    ans += (b-K)*(N//b)
    ans += max(0, N%b + (1 - K if K!=0 else 0))
print(ans)