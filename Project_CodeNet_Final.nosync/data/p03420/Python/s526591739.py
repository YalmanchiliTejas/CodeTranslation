N,K=map(int,input().split())
if K==0:
  print(N**2)
  exit(0)
ans=0
for i in range(K+1,N+1):
  base=i-(K-1)-1
  ans+=(N//i)*base
  rest=N%i
  ans+=max(rest-(K-1),0)
print(ans)