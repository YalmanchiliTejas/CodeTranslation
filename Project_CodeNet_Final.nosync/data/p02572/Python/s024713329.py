N = int(input())
A = list(map(int, input().split()))

answer = 0
x = 0
for i in range(len(A) - 1):
  x += A[i]
  answer +=  (x * A[i + 1])

print(answer% (10**9 + 7))