N,K=map(int,input().split())
if K==0:
  print(N**2)
  exit(0)
ans=0
for i in range(K+1,N+1):
  cur=0
  base=i-(K-1)-1
  cur+=(N//i)*base
  rest=N%i
  cur+=max(rest-(K-1),0)
  ans+=cur
print(ans)