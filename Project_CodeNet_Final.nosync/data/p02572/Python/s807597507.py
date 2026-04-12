# = map(int, input().split())
N = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7
S = sum(A)%mod
ans = 0
for k in range(N-1):
  S -= A[k]
  S %= mod
  ans += S*A[k]
  ans %= mod
print(ans)