N, M = map(int, input().split())

E = [list(map(int, input().split())) for i in range(M)]

visited = [0] * N
visited[0] = 1

ans = 0

def DFS(v,cnt):
  #print("call",v,cnt,visited)
  if sum(visited) == N:
    cnt += 1
    return cnt
  for i in range(M):
    if E[i][0] == v + 1:
      v_next = E[i][1] - 1
    elif E[i][1] == v + 1:
      v_next = E[i][0] - 1
    else:
      continue
    
    if visited[v_next] == 1:
      continue
    
    #print("deppen",v, v_next,visited)
    visited[v_next] = 1
    cnt = DFS(v_next,cnt)
    visited[v_next] = 0
    
  return cnt

ans = DFS(0,0)

print(ans)