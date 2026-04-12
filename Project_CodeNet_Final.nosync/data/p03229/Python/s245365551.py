N = int(input())
A = []
for i in range(N):
    A.append(int(input()))

A.sort()

if N % 2 == 1:
    w = -2*sum(A[:N//2]) +A[N//2] +A[N//2 + 1] + 2*sum(A[N//2 + 2:])
    m = -2*sum(A[:N//2-1]) - A[N//2 - 1] - A[N//2] + 2*sum(A[N//2+1:])
    print(max(w, m))
else:
    print(-2*sum(A[:N//2-1]) - A[N//2-1] + A[N//2] + 2*sum(A[N//2+1:]))