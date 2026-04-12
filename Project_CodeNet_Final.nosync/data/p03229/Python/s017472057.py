N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()

if N % 2 == 0:
    s = N//2
    d = -2 * sum(A[:s]) + A[s-1] - A[s] + 2 * sum(A[s:])
else:
    s = N//2
    d1 = -2 * sum(A[:s]) - A[s] - A[s+1] + 2 * sum(A[s:])
    s += 1
    d2 = -2 * sum(A[:s]) + A[s-2] + A[s-1] + 2 * sum(A[s:])
    d = max(d1, d2)

print(d)
