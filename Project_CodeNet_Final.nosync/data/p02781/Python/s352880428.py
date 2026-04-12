from functools import lru_cache
@lru_cache(None)
def f(n,k):
  if k<1: return 1
  if n<10:
    if k<2: return n
    return 0
  d,m=n//10,n%10
  return f(d,k-1)*m+f(d-1,k-1)*(9-m)+f(d,k)
print(f(int(input()),int(input())))