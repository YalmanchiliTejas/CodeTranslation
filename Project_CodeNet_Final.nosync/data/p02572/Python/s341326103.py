N = int(input())
A = list(map(int, input().split()))

MOD = 10**9 + 7

ans = 0
t = 0
for i in range(N-1):
  t += A[-1-i]
  ans += A[-2-i] * t % MOD
  ans %= MOD
print(ans)
