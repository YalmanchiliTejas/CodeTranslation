from functools import lru_cache
n=int(input())
k=int(input())
@lru_cache(None)
def cal(n,k):
  if n<10:
    if k==0: return 1
    if k==1: return n
    return 0
  q,r=divmod(n,10)
  ret=0
  if k>=1:
    ret+=cal(q,k-1)*r
    ret+=cal(q-1,k-1)*(9-r)
  ret+=cal(q,k)
  return ret

print(cal(n,k))