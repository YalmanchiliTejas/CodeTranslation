import copy

def func(graph, array, n):
  ans = 0
  for v in graph[n]:
    if not array[v]:
      cp_array = copy.deepcopy(array)
      cp_array[v] = True
      
      if [True]*len(array) == cp_array:
        ans += 1
      else:
        ans += func(graph, cp_array, v)

  return ans

n,m = map(int, input().split())
graph = [[] for i in range(n)]

for i in range(m):
  a,b = map(int, input().split())
  a -= 1
  b -= 1
  graph[a].append(b)
  graph[b].append(a)
  
array = [False] * n
array[0] = True
print(func(graph, array, 0))