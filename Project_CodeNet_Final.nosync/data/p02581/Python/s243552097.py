N = int(input())
A = list(map(int,input().split()))

if N==1:
    if A[0]==A[1]==A[2]:
        print(1)
    else:
        print(0)
    exit()

INF = float('inf')
ans = 0
dp = [[-INF]*(N+1) for _ in range(N+1)]
dp[A[0]][A[1]] = dp[A[1]][A[0]] = 0
maxdp = [max(row) for row in dp]
use = {A[0], A[1]}

for i in range(N-1):
    a,b,c = A[i*3+2:i*3+5]
    if a==b==c:
        ans += 1
        continue
    update = []
    if a==b:
        for j in use:
            update.append((j,c, max(dp[a][j], dp[j][a]) + 1))
    elif b==c:
        for j in use:
            update.append((j,a, max(dp[b][j], dp[j][b]) + 1))
    elif c==a:
        for j in use:
            update.append((j,b, max(dp[c][j], dp[j][c]) + 1))
    update.append((a,b, dp[c][c] + 1))
    update.append((b,c, dp[a][a] + 1))
    update.append((c,a, dp[b][b] + 1))
    mx = max(maxdp)
    update.append((a,b, mx))
    update.append((b,c, mx))
    update.append((c,a, mx))
    for j in use:
        update.append((j,a, maxdp[j]))
        update.append((j,b, maxdp[j]))
        update.append((j,c, maxdp[j]))
    for l,m,n in update:
        dp[l][m] = dp[m][l] = max(dp[l][m], dp[m][l], n)
        maxdp[l] = max(maxdp[l], n)
        maxdp[m] = max(maxdp[m], n)
    use.add(a)
    use.add(b)
    use.add(c)

tmp = max(maxdp)
tmp = max(tmp, dp[A[-1]][A[-1]] + 1)
ans += tmp
print(ans)