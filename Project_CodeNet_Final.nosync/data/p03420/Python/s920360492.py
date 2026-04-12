
N,K = list(map(int,input().split()))
ans = 0

for i in range(N):
    b=i+1
    p=int(N/b)
    
    ans+=max(0,b-K)*p+max(0,N-p*b-K+1)
    if K==0:
        ans-=1

print(ans)