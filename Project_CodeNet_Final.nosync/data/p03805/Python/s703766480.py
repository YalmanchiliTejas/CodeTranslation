n,m=list(map(int,input().split()))
graph=[[] for _ in range(n)]
res=0
for i in range(m):
  a,b=list(map(int,input().split()))
  graph[a-1].append(b)
  graph[b-1].append(a)

def solve(s,p):
  global res
  dp=format(s,'08b')[::-1]
  if s == (1<<n)-1 :
    res += 1
    return res
  for u in graph[p-1]:
    if dp[u-1] == '1':
      continue
    res = solve(s|(1<<(u-1)),u)
  return res

print(solve(1,1))