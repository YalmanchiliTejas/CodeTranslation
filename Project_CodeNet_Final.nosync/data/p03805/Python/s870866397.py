import sys
import numpy as np

N, M = [int(i) for i in sys.stdin.readline().split()]
edges = [[] for _ in range(N)]
for l in sys.stdin.readlines():
  a, b = [int(i)-1 for i in l.strip().split()]
  edges[a].append(b)
  edges[b].append(a)

def search(p, current_paths):
  #print(current_paths)
  finished_paths = [path for path in current_paths if p in path and len(path) == N]
  unfinished_paths = [tuple(list(path) + [p]) for path in current_paths if p not in path]
  if not unfinished_paths:
    return finished_paths

  paths = []
  for target in edges[p]:
    new_paths = search(target, unfinished_paths)
    paths += new_paths
  paths += finished_paths
  return set(paths + finished_paths)
  
res = search(0, [()])
print(len(res))