import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, M = mapint()
query = [[] for _ in range(N)]
for _ in range(M):
    a, b = mapint()
    query[a-1].append(b-1)
    query[b-1].append(a-1)

dp = [[0]*N for _ in range(1<<N)]
dp[1][0] = 1
for i in range(1<<N):
    for j in range(N):
        # 今jにいて、いったことのない場所に行く
        for nx in query[j]:
            if not (i>>nx)&1:
                dp[i+(1<<nx)][nx] += dp[i][j]

print(sum(dp[-1]))