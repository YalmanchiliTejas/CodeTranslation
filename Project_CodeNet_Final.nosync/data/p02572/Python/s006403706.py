N = int(input())
A = list(map(int, input().split()))
sum_a = 0
sum = 0

for i in range(N):
  sum_a += A[i] 

for i in range(N):
  sum_a -= A[i]
  sum += A[i] * sum_a
  ans = sum % (10**9 + 7)

print(ans)
