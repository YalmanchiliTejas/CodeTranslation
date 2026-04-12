N = int(input())
A = list(map(int, input().split()))

M = 0
sum = 0
for i in range(N):
  sum += A[i]

for i in range(N-1):
  sum = sum - A[i]
  M += A[i] * sum
  if M > 10 ** 9 + 7:
    M = M % (10 ** 9 + 7)
print(M)