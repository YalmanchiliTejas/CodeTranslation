N = int(input())
A = [0] * N
for i in range(N):
    A[i] = int(input())

A = sorted(A)

if N % 2 == 0:
    c = N // 2 - 1
    print((sum(A[c+2:]) - sum(A[:c])) * 2 + (A[c+1] - A[c]))
else:
    c = (N - 1) // 2
    t = max(2*A[c+1] - A[c] - A[c-1], A[c+1] + A[c] - 2 * A[c-1])
    print(t + (-sum(A[:c-1]) + sum(A[c+2:])) * 2)
