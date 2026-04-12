
from collections import deque
from copy import deepcopy

def parse():
  N, M = map(int, input().split(" "))
  # A, B = [], []
  edges = [[] for n in range(N)]
  for m in range(M):
    a, b = map(int, input().split(" "))
    edges[a - 1].append(b - 1)
    edges[b - 1].append(a - 1)
  return N, M, edges

def main():
  N, M, edges = parse()
  # print(N, M, edges)

  # visited = [False for n in range(N)]
  stack = deque([(0, edges[0], [False for n in range(N)])])
  ans = 0
  while len(stack) > 0:
    i, paths, visited = stack.pop()
    visited[i] = True
    for path in paths:
      # print("next_path:", path)
      if not visited[path]:
        stack.append((path, edges[path], deepcopy(visited)))
    
    # print(i, paths, visited)
    if not (False in visited):
      ans += 1

  print(ans)

if __name__ == "__main__":
  main()
