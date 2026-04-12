N = int(input())
A = list(map(int, input().split()))
MOD = 1000000007
sum = 0
for i in range(N):
    sum = sum + A[i]

res = 0
for i in range(N):
    sum = sum - A[i]
    res = res + (A[i] % MOD * sum % MOD)

print(res % MOD)