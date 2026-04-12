N = int(input())
A = list(map(int, input().split()))

total = 0
sum_val = sum(A[1:N])
for i in range(N-1):
  total += A[i]*sum_val
  total %= (10**9+7)
  sum_val -= A[i+1]
print(total)