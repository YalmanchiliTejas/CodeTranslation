N = int(input())
A = list(map(int, input().split()))
S = [0]

mod = 10**9 + 7

for i in range(N-1):
  S.append(S[-1] + A[-1-i])

S.reverse()

ans = 0

for i in range(N-1):
  ans += A[i] * S[i] % mod
  ans %= mod

print(ans)