def search(graph, n):
  result = [[] for _ in range(n)]
  if(1 in graph):
    result[0] = [1]
    for nxt in graph[1]:
      if(nxt in graph):
        result[1].append([1, nxt])
        if(2 == n):
          continue
        for nxt2 in graph[nxt]:
          if(nxt2 in graph):
            result[2].append([1, nxt, nxt2])
            if(3 == n):
              continue
            for nxt3 in graph[nxt2]:
              if(nxt3 in graph):
                result[3].append([1, nxt, nxt2, nxt3])
                if(4 == n):
                  continue
                for nxt4 in graph[nxt3]:
                  if(nxt4 in graph):
                    result[4].append([1, nxt, nxt2, nxt3,nxt4])
                    if(5 == n):
                      continue
                    for nxt5 in graph[nxt4]:
                      if(nxt5 in graph):
                        result[5].append([1, nxt, nxt2, nxt3,nxt4,nxt5])
                        if(6 == n):
                          continue
                        for nxt6 in graph[nxt5]:
                          if(nxt6 in graph):
                            result[6].append([1, nxt, nxt2, nxt3,nxt4,nxt5,nxt6])
                            if(7 == n):
                              continue
                            for nxt7 in graph[nxt6]:
                              if(nxt7 in graph):
                                result[7].append([1, nxt, nxt2, nxt3,nxt4,nxt5,nxt6,nxt7])
  return result

n, m = list(map(int, input().split()))
route = [False for _ in range(n)]
gh = {}
for i in range(m):
  start,end = list(map(int, input().split()))
  if(start in gh):
    gh[start].add(end)
  else:
    gh[start] = {end}
  if(end in gh):
    gh[end].add(start)
  else:
    gh[end] = {start}
    
ans = search(gh,n) 
cnt = 0
for arr in ans[n-1]:
  if(set(arr) == {i for i in range(1, n+1)}):
    cnt +=1
print(cnt)