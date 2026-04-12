from functools import lru_cache
@lru_cache(None)
def f(n,k):
  if n<10:
    if k<1: return 1
    if k<2: return n
    return 0
  d,m=divmod(n,10)
  c=0
  if k:
    c+=f(d,k-1)*m
    c+=f(d-1,k-1)*(9-m)
  c+=f(d,k)
  return c
print(f(int(input()),int(input())))