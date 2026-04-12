N = int(input())
A = list(map(int, input().split()))

MOD = 10**9 + 7

sum_A = [0] * N
sum_A[0] = A[0]

for i in range(1, N):
  sum_A[i] = sum_A[i-1] + A[i]

print(sum([sa*a for sa,a in zip(sum_A[:-1], A[1:])]) % MOD)
