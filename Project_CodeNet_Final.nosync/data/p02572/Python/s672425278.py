
MOD = 10 ** 9 + 7

N = int(input())

A = list(map(int, input().split()))

# import random
# N = 200_000
# A = [random.randint(1, 2000) for i in range(N)]

res = 0

cum_sum = sum(A)

for i in range(N - 1):
    cum_sum -= A[i]
    res += (A[i] * cum_sum) % MOD

res %= MOD

print(res)