N,M=map(int,input().split())
edges = [input().split() for x in range(M)]
path = []
for i in range(M):
  if '1' == edges[i][0]:
    path.append('1' + edges[i][1])

while 0 < len(path):
  if len(path[0]) == N:
    break 
  work = path.pop(0)
  for j in range(M):
    if (work[-1] == edges[j][0]) and edges[j][1] not in work:
      path.append(work + edges[j][1])
    elif (work[-1] == edges[j][1]) and edges[j][0] not in work:
      path.append(work + edges[j][0])

print(len(path))