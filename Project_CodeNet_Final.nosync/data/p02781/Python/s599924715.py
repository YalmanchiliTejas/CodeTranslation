from functools import lru_cache
N = int(input())
K = int(input())
@lru_cache(None)
def F(N,K):
#  assert N>=0
  if N<10:
    if K==0:
      return 1
    if K==1:
      return N
    return 0
  p, q = divmod(N,10)
  ret = 0
  if K>0:
    ret += F(p,K-1) * q
    ret += F(p-1,K-1) * (9-q)
  ret += F(p,K)
  return ret
print(F(N,K))