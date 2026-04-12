N,K = map(int,input().split())
if K == 0:
    print(N*N)
    exit()

ans = 0
for b in range(K+1,N+1):
    ans += ((N+1)//b) * (b-K) + max(0, (N+1)%b - K)
print(ans)
