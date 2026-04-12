n,m = map(int,input().split())
graph = {i+1:[] for i in range(n)}
for _ in range(m):
  a,b = map(int,input().split())
  graph[a].append(b)
  graph[b].append(a)

def func(path,p,count):
  if len(path) == n:
    return count + 1
  for i in graph[p]:
    if i in path:
      continue
    count = func(path+[i],i,count)
  return count
print(func([1],1,0))


