N,K=map(int,input().split())

if K==0:
    print(N*N)
    exit()

X=0
for b in range(1,N+1):
    if b<=K:
        X+=N+1
    else:
        q,r=divmod(N,b)
        X+=K*q+min(r+1,K)
print(N*(N+1)-X)