N = int(input())
A = [0] * N
for i in range(N):
    A[i] = int(input())

sorted_A = sorted(A, reverse=True)

if N % 2 == 0:
    ans = sum(sorted_A[:(N - 2) // 2]) * 2 + sorted_A[(N - 2) // 2] - sorted_A[(N - 2) // 2 + 1] - sum(sorted_A[(N - 2) // 2 + 2:] * 2)
else:
    ans_a = sum(sorted_A[:(N - 2) // 2]) * 2 + sum(sorted_A[(N - 2) // 2: (N - 2) // 2 + 2]) - sum(sorted_A[(N - 2) // 2 + 2:]) * 2
    ans_b = sum(sorted_A[:(N - 1) // 2]) * 2 - sum(sorted_A[(N - 1) // 2: (N - 1) // 2 + 2]) - sum(sorted_A[(N - 1) // 2 + 2:]) * 2
    ans = max(ans_a, ans_b)
print(ans)
