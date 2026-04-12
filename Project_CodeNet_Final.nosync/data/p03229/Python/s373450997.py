N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()
A = A[::-1]

if N % 2:
  a = sum(A[:(N - 1) // 2])
  b = sum(A[(N - 1) // 2:(N - 1) // 2 + 2])
  c = sum(A[(N - 1) // 2 + 2:])
  answer = a * 2 + b * (-1) + c * (-2)
  a = sum(A[:(N - 3) // 2])
  b = sum(A[(N - 3) // 2:(N - 3) // 2 + 2])
  c = sum(A[(N - 3) // 2 + 2:])
  answer = max(answer, a * 2 + b + c * (-2))
else:
  a = sum(A[:(N - 2) // 2])
  b = A[(N - 2) // 2:(N - 2) // 2 + 2]
  c = sum(A[(N - 2) // 2 + 2:])
  answer = a * 2 + b[0] - b[1] + c * (-2)
print(answer)  