N,K=map(int,input().split())

if K==0:
    print(N**2)
    exit()

ans=0
for i in range(K+1,N+1):
    ans+=N//i*(i-K)+max(0,N%i-(K-1))
print(ans)