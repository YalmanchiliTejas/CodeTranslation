N = int(input())
A = list(map(int, input().split()))
mod = 10 ** 9 + 7

now = sum(A) % mod
ans = 0

for i in range(N):
  now -= A[i]
  now %= mod
  ans += A[i] * now
  ans %= mod
print(ans % mod)  


