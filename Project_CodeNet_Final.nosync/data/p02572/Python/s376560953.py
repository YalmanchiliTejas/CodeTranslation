N = int(input())
A = list(map(int, input().split()))
a = 0
ans = 0
mod = 10**9 + 7
for i in range(N-1):
  a += A[N-i-1]
  ans += A[N-i-2] * a
print(ans%mod)