import itertools

n,m = map(int, input().split())
edge_set = {tuple(map(int, input().split())) for _ in range(m)}
counter = 0

for i in itertools.permutations(range(2, n+1), n-1):
  path = [1] + list(i)
  path_set = {tuple(sorted(edge)) for edge in zip(path, path[1:])}
  
  if path_set <= edge_set:
    counter += 1
 
  
print(counter)