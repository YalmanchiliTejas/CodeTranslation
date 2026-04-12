n, m = map(int, input().split())

P = [[0] * n for i in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    P[a-1][b-1] = 1
    P[b-1][a-1] = 1

#dp[S][v] := 頂点０から出発し、集合Sに含まれる頂点を全て訪れるpathのうち、頂点vが最後になるようなpathの総数
dp = [[0] * n for _ in range(1 << n)]

#dpの初期化 dp({0}, 0) = 1
dp[1][0] = 1

for S in range(1 << n):
    for v in range(n):
        #vがSに含まれていないときはパスする
        if S & (1 << v) == 0:
            continue
        
        #sub = S - {v}
        sub = S ^ (1 << v)
        
        for u in range(n):
            #subにuが含まれており、かつuとvが辺で結ばれている
            if sub & (1 << u) and P[u][v]:
                dp[S][v] += dp[sub][u]

ans = sum(dp[(1 << n) - 1][u] for u in range(1, n))
print(ans)