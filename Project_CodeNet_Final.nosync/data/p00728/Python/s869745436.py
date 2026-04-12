while True:
  n=int(input())
  if n==0:
    break
  m=10000
  M=0
  sum=0
  for i in range(n):
    s=int(input())
    m=min(m,s)
    M=max(M,s)
    sum=sum+s
  print((sum-M-m)//(n-2))
