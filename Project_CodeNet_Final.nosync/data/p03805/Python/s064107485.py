import itertools
N,M=map(int,input().split())

graph=[[] for _ in range(N+1)]
for _ in range(M):
  a,b=map(int,input().split())
  graph[a].append(b)
  graph[b].append(a)
#print(graph)

answer=0
for perm in itertools.permutations(range(2,N+1)):
  path=[1]+list(perm)
  #print(path)
  
  for i in range(1,N):
    u=path[i-1]
    v=path[i]
    if not v in graph[u]:
      break
  else:
    answer+=1
    
print(answer)