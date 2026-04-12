N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()
if N % 2 == 0:
    print(-2*sum(A[:N//2-1]) - A[N//2-1] + A[N//2] + 2*sum(A[N//2+1:]))
else:
    m = max(-2*A[N//2-1] + A[N//2] + A[N//2+1], - A[N//2-1] - A[N//2] + 2*A[N//2+1])
    print(-2*sum(A[:N//2-1]) + m + 2*sum(A[N//2+2:]))