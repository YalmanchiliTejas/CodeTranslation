N,X=map(int,input().split())
def f(n,x):
  if x==1 and n==0:
    return 1
  if x==1:
    return 0
  if x==2**(n+2)-3:
    return 2**(n+1)-1
  if x==2**(n+1)-1:
    return 2**n
  res=0
  if 1<x<2**(n+1)-1:
    res=f(n-1,x-1)
    return res
  if 2**(n+1)-1<x<2**(n+2)-3:
    res=2**n+f(n-1,x-2**(n+1)+1)
    return res
print(f(N,X))
    