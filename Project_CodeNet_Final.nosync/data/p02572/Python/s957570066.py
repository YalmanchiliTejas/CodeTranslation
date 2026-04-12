def solve():
  N = int(input())
  A = list(map(int, input().split()))
  mod = 10**9+7
  ans = sum(A)**2
  for i in range(N):
    ans -= A[i]**2
  ans //=2
  return ans%mod
print(solve())