N = int(input())
A = list(map(int,input().split()))
SUMA = sum(A)
MOD = 10**9 + 7
C = [0] * (N-1)
for i in range(N-1):
  SUMA -= A[i]
  C[i] = SUMA
ans = 0
for i in range(N-1):
  ans += A[i]*C[i]
  ans %= MOD
print(ans)