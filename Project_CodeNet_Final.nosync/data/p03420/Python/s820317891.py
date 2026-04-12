N,K=map(int,input().split())

if K==0:
  print(N**2)
else:
  ans=0
  for i in range(K+1,N+1):
    ans+=(N-N%i)//i*(i-K)
    ans+=N%i-K+1if N%i>=K else 0
  print(ans)