N,K = map(int,input().split())
if K == 0:
    print(N*N)
    exit()

ans = 0
for b in range(K+1,N+1):
    d,m = divmod(N,b)
    ans += d*(b-K) + max(0,m+1-K)
print(ans)