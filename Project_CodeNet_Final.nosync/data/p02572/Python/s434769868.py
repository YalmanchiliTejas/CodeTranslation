N = int(input())
A = list(map(int, input().split()))

MOD = 10**9 + 7
# MOD = 10

sum_A = 0
for i in range(N):
    sum_A += A[i]
    # sum_A %= MOD
 
ans = (sum_A * sum_A) # % MOD

for i in range(N):
    ans -= (A[i] * A[i]) # % MOD
    # ans %= MOD

ans //= 2
ans %= MOD

print(ans)
