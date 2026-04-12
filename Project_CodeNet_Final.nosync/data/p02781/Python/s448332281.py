from functools import lru_cache
N = int(input())
K = int(input())
@lru_cache(None)
def f(n,k):
  if k<0:
    return 0
  if n<10:
    if k>1:
      return 0
    elif k==1:
      return n
    elif k==0:
      return 1
  a, b = divmod(n,10)
  m = 9*f(a-1,k-1)+f(a,k)+b*(f(a,k-1)-f(a-1,k-1))
  return m
print(f(N,K))