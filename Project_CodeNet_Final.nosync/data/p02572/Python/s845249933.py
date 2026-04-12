MOD = 10**9+7

N = int(input())
A = list(map(int, input().split()))

A_sum = sum(A)

r = 0
for i, a in enumerate(A):
    x = A[i]*(A_sum - a)
    r = (r+x) % MOD

# print(r)

r = (r * pow(2, MOD-2, MOD)) % MOD

print(r)