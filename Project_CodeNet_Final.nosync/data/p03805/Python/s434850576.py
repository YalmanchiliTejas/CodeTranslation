def bitDP():
    dp = [[0] * N for _ in range(1 << N)]
    dp[1][0] = 1
    for i in range(1 << N):
        for v in range(N):
            if  (i >> v) & 0:
                continue
            j = i ^ (1 << v)
            for u in range(N):
                if (j >> u) & 1 and v in E[u]:
                    dp[i][v] += dp[j][u]
    res = sum(dp[-1][u] for u in range(1, N))
    return res

N, M = map(int, input().split())
E = [set() for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    E[a-1].add(b-1)
    E[b-1].add(a-1)

print(bitDP())