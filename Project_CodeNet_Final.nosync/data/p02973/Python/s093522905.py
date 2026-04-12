import bisect

N = int(input())
A = [int(input()) for _ in range(N)]

C, Ci = [-1] * (N - 1) + [A[0]], N - 1


for i in range(1, N):
    bA = bisect.bisect_left(C, A[i])
    if bA == Ci:
        Ci -= 1
        C[Ci] = A[i]
    else:
        C[bA - 1] = A[i]

print(N - Ci)
