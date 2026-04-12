N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()

if N % 2 == 0:
    c = N // 2
    S = -2 * sum(A[:c]) + 2 * sum(A[c:]) + A[c-1] - A[c]
else:
    c = (N-1) // 2
    tmp1 = -2 * sum(A[:c]) + 2 * sum(A[c+2:]) + A[c] + A[c+1]
    tmp2 = -2 * sum(A[:c-1]) + 2 * sum(A[c+1:]) - A[c-1] - A[c]
    S = max(tmp1, tmp2)

print(S)