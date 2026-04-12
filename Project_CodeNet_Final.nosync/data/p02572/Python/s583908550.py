N = int(input())
A = [ int(v) for v in input().split(" ") ]

sum_A = sum(A)
total = 0
for i in range(N):
  sum_A -= A[i]
  total += A[i] * sum_A

print(total % (10**9+7))