n, m = map(int, input().split())
l = []
combo = []
for i in range(max(n, m)+1):
  l.append([])
  
def dfs(path, now):
  if len(set(path)) == n and not path in combo:
    combo.append(path)
    return

  for i in l[now]:
    if not i in path:
      temp = path[:]
      temp.append(i)
      dfs(temp, i)

  return

if m == 0:
  print(0)
else:

  for i in range(m):
    f, t = map(int, input().split())
    if not t in l[f]:
      l[f].append(t)
    
    if not f in l[t]:
      l[t].append(f)

  dfs([1], 1)
  print(len(combo))