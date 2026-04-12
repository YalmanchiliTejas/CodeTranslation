N, *A = map(int, open(0).read().split())
M = N // 2
A.sort()
ans = 0
if N % 2:
    for i in range(1, M):
        ans += A[i + M + 1] - A[i - 1]
        ans += A[i + M + 1] - A[i]
    ans += A[M + 1] - A[0]
    ans = max(A[M + 1] - A[M] + ans, ans + A[M] - A[M - 1])
else:
    ans += A[M] - A[0]
    for i in range(1, M):
        ans += A[i + M] - A[i - 1]
        ans += A[i + M] - A[i]
print(ans)
