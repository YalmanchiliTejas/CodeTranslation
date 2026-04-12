import sys

sys.setrecursionlimit(500005)
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()


n = ni()
a = na()

dp = [[-99999999] * (n+1) for _ in range(n+1)]
dp[a[0]][a[1]] = 0

dprow = [-99999999] * (n+1)
dprow[a[0]] = 0
dprow[a[1]] = 0

margin = 0
for i in range(2, 3*n-2, 3):
    if a[i] == a[i+1] and a[i+1] == a[i+2]:
        margin += 1
    else:
        q = []
        for jj in range(i, i+3):
            if dp[a[jj]][a[jj]] < 0:
                continue
            if jj == i:
                q.append((a[i+1], a[i+2], dp[a[jj]][a[jj]] + 1))
            if jj == i+1:
                q.append((a[i], a[i+2], dp[a[jj]][a[jj]] + 1))
            if jj == i+2:
                q.append((a[i], a[i+1], dp[a[jj]][a[jj]] + 1))

        for jj in range(i, i+3):
            for kk in range(jj+1, i+3):
                if a[jj] == a[kk]:
                    rem = i+i+1+i+2-jj-kk
                    for t in range(n+1):
                        if dp[a[jj]][t] >= 0:
                            q.append((t, a[rem], dp[a[jj]][t] + 1))
                        if dp[t][a[jj]] >= 0:
                            q.append((t, a[rem], dp[t][a[jj]] + 1))
        for j in range(n+1):
            if dprow[j] >= 0:
                for k in (a[i], a[i + 1], a[i + 2]):
                    q.append((j, k, dprow[j]))
        mx = max(dprow)
        for jj in range(i, i+3):
            for kk in range(jj+1, i+3):
                q.append((a[jj], a[kk], mx))
        for u in q:
            dp[u[0]][u[1]] = max(dp[u[0]][u[1]], u[2])
            dprow[u[0]] = max(dprow[u[0]], u[2])
            dprow[u[1]] = max(dprow[u[1]], u[2])
        # print(i)
        # for row in dp:
        #     print(row)
        # print(dprow)
        # print(dpcol)

ans = max(*dprow, dp[a[-1]][a[-1]] + 1)

print(ans+margin)
