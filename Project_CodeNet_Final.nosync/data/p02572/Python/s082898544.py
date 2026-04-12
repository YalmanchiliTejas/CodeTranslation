N = int(input())
A = list(map(int,input().split()))

MOD = 10**9+7
ans = 0

mul = [0]*(N+1)

for i in range(N):
  mul[i+1] = mul[i]+A[i]
  mul[i+1] = mul[i+1]%MOD
  
for i in range(N-1):
  ans += A[i] * (mul[-1]-mul[i+1])
  ans %= MOD
  
print(ans)