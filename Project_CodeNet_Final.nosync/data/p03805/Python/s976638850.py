N,M = map(int,input().split())
data =[[] for i in range(N+1)]
for i in range(M):
  a,b = map(int,input().split())
  data[a].append(b)
  data[b].append(a)

def dfs(cur,*a): #現在地、通った場所→
  if cur in a:
    return 0
  else:
    if len(a) == N-1:
      return 1
    else:
      a = list(a)
      a.append(cur)
      count = 0
      for i in data[cur]:
        count += dfs(i,*a)
      return count
print(dfs(1,*[]))