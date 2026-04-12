N = int(input())
A = [int(s) for s in input().split()]

s = sum(A)
result = 0

MOD = 10**9 + 7

for i in range(N - 1):
    s = s - A[i]
    result = result + (A[i] * s % MOD)
print(result % MOD)