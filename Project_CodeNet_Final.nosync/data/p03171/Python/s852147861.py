N = int(input())
*A, = map(int, input().split())
dp = [[-1]*(N+1-i) for i in range(N+1)]
for i in range(N+1):
    dp[0][i] = 0
t = (N & 1)
for l in range(1, N+1):
    S = dp[l-1]; T = dp[l]
    t ^= 1
    if t:
        T[:] = (min(S[i+1] - A[i], S[i] - A[i+l-1]) for i in range(N-l+1))
    else:
        T[:] = (max(S[i+1] + A[i], S[i] + A[i+l-1]) for i in range(N-l+1))
print(dp[N][0])