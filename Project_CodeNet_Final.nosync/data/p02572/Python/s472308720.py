N = int(input())
A = list(map(int,input().split()))
MOD = 1000000007
x = sum(A)
ans = 0
 
for i in range(N):
  x -= A[i]
  y = x % MOD
  z = (A[i] * y) % MOD
  ans += z
  ans %= MOD

print(ans)
