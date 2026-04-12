N,K = list(map(int,input().split()))
ans = 0
if K == 0:
    print(N**2)
else:
    for i in range(K+1,N+1):
        ans += N//i*(i-K)
        ans += max(0,N%i-K+1)
    print(ans)