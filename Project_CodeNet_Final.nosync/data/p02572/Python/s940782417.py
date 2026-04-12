N = int(input())
A = list(map(int, input().split()))

res = 0
sums = sum(A)
for i in range(len(A)):
  sums = sums - A[i]
  a = A[i]
  res += ((a * sums) % (10 ** 9 + 7))
print(res % (10 ** 9 + 7))