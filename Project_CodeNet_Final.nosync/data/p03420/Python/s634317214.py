N,K=map(int,input().split())

ans=0
if K==0:
  ans=N**2
else:
  for b in range(1,N+1):
    ans+=max(N%b-K+1,0)
    ans+=max(b-K,0)*(N//b-K//b)
print(ans)