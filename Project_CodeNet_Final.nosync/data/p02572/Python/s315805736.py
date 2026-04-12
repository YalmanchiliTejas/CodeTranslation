N = int(input())
A = list(map(int,input().split()))

sum_A = sum(A) % (10 ** 9 + 7)
ans = 0

for i in range(len(A)):
  if sum_A - A[i] < 0:
    sum_A = sum_A - A[i] + (10 ** 9 + 7)
  else:
    sum_A -= A[i]
  ans += A[i] * sum_A % (10 ** 9 + 7)

print(ans % (10 ** 9 + 7))