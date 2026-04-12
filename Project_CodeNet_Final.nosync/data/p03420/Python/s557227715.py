N,K=map(int,input().split())
ans=0
for i in range(K+1,N+1):
    ans+=(N//i)*(i-K)
    ans+=max(N-((N//i)*i)-max(K-1,0),0)
print(ans)