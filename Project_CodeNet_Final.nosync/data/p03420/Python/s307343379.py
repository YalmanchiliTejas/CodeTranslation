N,K = map(int,input().split())
ans = 0
for bi in range(K+1,N+1):
    ans += (bi-K)*(N//bi)+max(0,N%bi-K+1) - (K==0)
print(ans)
