N = int(input())
A = list(map(int, input().split()))
mod = int(1e9) + 7
R = [0 for _ in range(N+1)]
for i in range(N):
  R[i+1] = R[i] + A[i]
S = 0
for i in range(N-1):
  S += A[i] * (R[N] - R[i+1]) % mod
  S %= mod
print(S)