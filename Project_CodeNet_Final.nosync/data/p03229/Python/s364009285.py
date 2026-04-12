N = int(input())
A = [int(input()) for i in range(N)]

A.sort()
ans = 0
if N % 2 == 0:
    h = (N - 2) // 2
    ans = -2 * sum(A[:h]) - A[h] + A[h + 1] + 2 * sum(A[h + 2:])
else:
    h = (N - 3) // 2
    m1 = -2 * sum(A[:h + 1]) + sum(A[h + 1:h + 3]) + 2 * sum(A[h + 3:])
    m2 = -2 * sum(A[:h]) - sum(A[h:h + 2]) + 2 * sum(A[h + 2:])
    ans = max(m1, m2)
print(ans)
