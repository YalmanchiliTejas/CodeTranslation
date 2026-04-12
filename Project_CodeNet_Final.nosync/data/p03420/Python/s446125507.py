N,K=map(int,input().split())

if K == 0:
  print(N*N)
else:
  total = 0
  for i in range(1,N+1):
    if K <= (i-1):
      total += (N//i)*(i-K)
    if K <= (N%i):
      total += (N%i)-K+1
  print(total)