from collections import deque

n, m = map(int, input().split())
graph = [[] for i in range(n)]
for i in range(m):
  a, b = map(int, input().split())
  graph[a-1].append(b)
  graph[b-1].append(a)
  
seen = [False]*n
finished = [False]*n
count = 0

def dfs(v):
  global graph
  global seen
  global count
  
  seen[v] = True
  if seen == [True]*n:
    count += 1

  for next_v in graph[v]:
    if seen[next_v-1]: 
      continue
    dfs(next_v-1)
    
  seen[v] = False
  	
dfs(0)
print(count)