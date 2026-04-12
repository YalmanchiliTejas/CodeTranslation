from itertools import accumulate

N = int(input())
A = list(map(int, input().split()))
S = list(accumulate(A))
mod = 1000000007

ans = 0
for i in range(1, N):
  ans += (S[i-1]%mod)*(A[i]%mod)
  ans %= mod
print(ans%mod)