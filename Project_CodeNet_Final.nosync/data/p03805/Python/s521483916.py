import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


from collections import defaultdict
n,m = map(int, input().split())
ns = defaultdict(set)
for _ in range(m):
    u,v = map(int, input().split())
    u -= 1
    v -= 1
    ns[u].add(v)
    ns[v].add(u)
dp = [[0]*(1<<n) for _ in range(n)]
dp[0][1] = 1
for b in range(1, 1<<n):
    for u in range(n):
        for i in range(n):
            if not (b>>i&1) and i in ns[u]:
                dp[i][b+(1<<i)] += dp[u][b]
ans = sum(dp[u][(1<<n)-1] for u in range(n))
print(ans)