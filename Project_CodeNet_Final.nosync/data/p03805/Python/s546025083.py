N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for i in range(M):
  a, b = map(int, input().split())
  graph[a-1].append(b-1)
  graph[b-1].append(a-1)
dp = [[0]*N for _ in range(1<<N)]
#dp[i][j]:=集合iをすでに通っていて、最後が頂点jのときの組み合わせ
dp[1][0] = 1

for bit in range(1<<N):
  for n in range(N):
    if(bit>>n & 1 == 0):
      continue
    for to in graph[n]:
      if(bit>>to & 1 == 1):
        continue
      next_bit = bit | (1<<to)
      dp[next_bit][to] += dp[bit][n]

ans = 0
for i in range(1, N):
  ans += dp[(1<<N)-1][i]
print(ans)