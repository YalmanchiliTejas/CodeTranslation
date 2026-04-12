n,x=map(int,input().split())
a=[1]*51
p=[1]*51
for i in range(1,51):
  a[i]=a[i-1]*2+3
  p[i]=p[i-1]*2+1
def f(N,X):
  if N==0:
    return 1
  if X==1:
    return 0
  if X<a[N-1]+2:
    return f(N-1,X-1)
  if X==a[N-1]+2:
    return p[N-1]+1
  if X<a[N-1]*2+3:
    return p[N-1]+1+f(N-1,X-2-a[N-1])
  else:
    return p[N-1]*2+1
print(f(n,x))