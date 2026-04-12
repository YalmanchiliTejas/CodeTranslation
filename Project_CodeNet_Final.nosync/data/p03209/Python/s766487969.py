nn,xx=map(int,input().split())
def f(n,x):
  if x==0:
    return 0
  if n==0:
    return 1
  if x==2**(n+2)-3:
    return 2**(n+1)-1
  b=2**(n+1)-3
  u=min(b,max(0,x-2-b))
  l=min(x-1,b)
  return f(n-1,u)+(1 if x>b+1 else 0)+f(n-1,l)
print(f(nn,xx))