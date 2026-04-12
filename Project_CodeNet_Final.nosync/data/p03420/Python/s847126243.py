N,K = map(int,input().split())
if K==0:
    print(N*N)
    exit()

ans = 0
for b in range(K+1,N+1):
    d,m = divmod(N+1,b)
    ans += (b-K)*d
    ans += max(0, (m-1)-K+1)
print(ans)