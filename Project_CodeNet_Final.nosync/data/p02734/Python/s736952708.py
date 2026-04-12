P = 998244353

N, S = map(int, input().split())
A = list(map(int, input().split()))

dp0 = [[0]*(S+1) for _ in range(N)]
dp1 = [[0]*(S+1) for _ in range(N)]
dp2 = [[0]*(S+1) for _ in range(N)]

dp0[0][0] = 1
dp1[0][0] = 1
if A[0] <= S:
    dp1[0][A[0]] = 1

for i in range(1, N):
    dp0[i][0] = 1
    dp1[i][0] = dp1[i-1][0] + 1
    dp2[i][S] = dp2[i-1][S] + dp1[i-1][S]
    if A[i] == S:
        dp2[i][S] += dp1[i-1][0] + 1
        dp1[i][S] += dp1[i-1][0] + 1
    elif A[i] < S:
        dp1[i][A[i]] += 1 + dp1[i-1][0]
    for j in range(1, S+1):
        dp1[i][j] += dp1[i-1][j]
        if j + A[i] < S:
            dp1[i][j+A[i]] += dp1[i-1][j]
        elif j + A[i] == S:
            dp2[i][S] += dp1[i-1][j]
            dp1[i][S] += dp1[i-1][j]
        dp0[i][j] %= P
        dp1[i][j] %= P
        dp2[i][j] %= P

print(dp2[N-1][S])