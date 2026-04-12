N,K=map(int,input().split())

if K==0:
    print(N**2)
    exit()

ans=0
for i in range(K+1,N+1):
    ans+=(((N+1)//i)*(i-K))
    ans+=max((((N+1)%i)-K),0)
print(ans)