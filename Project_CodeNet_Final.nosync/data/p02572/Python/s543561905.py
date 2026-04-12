MOD = 10**9+7
N = int(input())
A = list(map(int, input().split()))
ans = (sum(A)%MOD)**2 % MOD
for i in range(N):
  X = (A[i]%MOD)**2 % MOD
  ans = (ans-X)%MOD
ans = ans*pow(2, MOD-2, MOD)%MOD
print(ans)