n = int(input())
A = [*map(int, input().split())]
MOD = (10**9)+7
sum_a = sum(A)
ans = 0
for i in range(n-1):
    sum_a -= A[i]
    ans = (ans + A[i] * sum_a) % MOD
print((ans + MOD) % MOD)
