N = int(input())
A = list(map(int, input().split()))
DP = [[0] * (N+1) for _ in range(N+1)]

for num in range(1, N + 1):
    for start in range(N):
        end = start + num
        if end > N:
            break
        if num == 1:
            DP[start][end] = A[start]
        else:
            DP[start][end] = max(A[start] - DP[start+1][end], A[end - 1] - DP[start][end - 1])
print(DP[0][N])
