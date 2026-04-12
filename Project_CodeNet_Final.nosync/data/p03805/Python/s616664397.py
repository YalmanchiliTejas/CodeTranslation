from collections import deque

def run():
  N, M = map(int, input().split())
  vertex_dict = {}
  for m in range(M):
    a, b = map(int, input().split())
    vertex_dict.setdefault(a, []).append(b)
    vertex_dict.setdefault(b, []).append(a)
  all_m_list = range(M)
  q = deque([])
  q.append((1, [1]))
  total = 0
  while True:
    #print(q)
    if len(q) == 0: break
    now_vertex, visited_list = q.popleft()
    if len(visited_list) == N:
      total += 1
      continue
    next_list = vertex_dict[now_vertex]
    for next_vertex in next_list:
      for visited_vertex in visited_list:
        if next_vertex == visited_vertex: break
      else:
        q.append((next_vertex, visited_list+[next_vertex]))
  print(total)
        
  
if __name__ == '__main__':
  run()