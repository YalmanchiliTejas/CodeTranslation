N = int(input())
A = list(map(int, input().split()))



A_sum = 0
for i in range(0, N, 1):
    A_sum = A_sum + A[i]

A_sum_sq = A_sum * A_sum

idv_sq_sum = 0
for i in range(0, N, 1):
    idv_sq_sum += A[i] * A[i]

Answer = (A_sum_sq -
          idv_sq_sum) // 2
print(Answer%(10**9 + 7))