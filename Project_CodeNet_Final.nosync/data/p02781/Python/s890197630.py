from functools import lru_cache

@lru_cache(None)
def solve(n,k) :
  if n<=9:
    if k==0: return 1
    if k==1: return n
    return 0
  m = n//10
  r = n%10
  return r*solve(m, k-1)+(9-r)*solve(m-1, k-1)+solve(m, k)

N = int(input())
K = int(input())
print(solve(N, K))