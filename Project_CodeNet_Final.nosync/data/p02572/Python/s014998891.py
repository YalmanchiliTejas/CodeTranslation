N = int(input())
A = list(map(int, input().split()))

A_sum = sum(A)
result = 0
for i in range(N):
    A_sum -= A[i]
    result += A[i] * A_sum % (10**9 + 7)
print(result % (10**9 + 7))
