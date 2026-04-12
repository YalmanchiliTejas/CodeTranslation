from functools import lru_cache
N = int(input())
K = int(input())

@lru_cache(None)

def F(N,K):
  assert N>=0
  if N<10:
    if K==0:
      return 1
    if K==1:
      return N
    return 0
  q,r = divmod(N,10)
  ret = 0
  if K>=1:
    ret += F(q,K-1)*r
    ret += F(q-1,K-1)*(9-r)
  ret += F(q,K)
  return ret

print(F(N,K))