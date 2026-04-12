MOD = 10**9 + 7

N = int(input())
A = list(map(int, input().split()))

res = 0
sumA = sum(A)
for i in range(N)[:-1]:
  sumA -= A[i]
  res += A[i] * sumA
  res %= MOD

print(res)