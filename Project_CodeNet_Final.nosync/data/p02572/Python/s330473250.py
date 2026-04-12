N = int(input())
A = [int(a) for a in input().split()]
mod = 10 ** 9 + 7
ans = 0
#TLE
'''
for i in range(N - 1):
  for j in range(i+1, N):
    a = A[i] % mod
    b = A[j] % mod
    ans += (a * b) % mod
    ans = ans % mod
'''
tot = 0
for i in range(N):
  A[i] %= mod
  tot += A[i]
  tot %= mod
for i in range(N-1):
  tot -= A[i]
  ans += (A[i] * tot) % mod
  ans %= mod
print(ans)