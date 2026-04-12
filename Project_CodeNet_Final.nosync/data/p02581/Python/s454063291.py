from collections import deque


def upd(a, b, v):
    global N
    dp[a][b] = max(dp[a][b], v)
    dp[b][a] = max(dp[b][a], v)
    dp[N][a] = max(dp[N][a], v)
    dp[N][b] = max(dp[N][b], v)
    dp[a][N] = max(dp[a][N], v)
    dp[b][N] = max(dp[b][N], v)
    dp[N][N] = max(dp[N][N], v)


N = int(input())
A = list(map(lambda x: int(x) - 1, input().split()))

INF = 1 << 32
dp = [[-INF] * (N + 1) for _ in range(N + 1)]
upd(A[0], A[1], 0)
base = 0

for i in range(2, 3 * N - 1, 3):
    x, y, z = A[i], A[i + 1], A[i + 2]
    if x == y == z:  # x, y, z 3文字すべて等しいとき
        base += 1
    else:
        q = deque()
        for _ in range(3):
            # a, b, x, y, z のうち, b, y, z を消すとき
            for k in range(N):
                v = dp[k][N]
                if y == z:
                    v = max(v, dp[k][y] + 1)
                q.append((k, x, v))
            # a, b, x, y, z のうち, a, b, z を消すとき
            v = max(dp[z][z] + 1, dp[N][N])
            q.append((x, y, v))
            # x, y, z をローテート
            x, y, z = z, x, y
        while q:
            a, b, v = q.popleft()
            upd(a, b, v)

l = A[-1]
ans = max(dp[N][N], dp[l][l] + 1)
print(ans + base)
