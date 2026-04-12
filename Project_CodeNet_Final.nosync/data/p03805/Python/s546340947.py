import itertools
N, M = map(int, input().split())

path = []
for _ in range(M):
  a, b = map(int, input().split())
  path.append([a, b])

all_routes = itertools.permutations(range(2, N+1))

count = 0
for route in all_routes:
  cur_path = path.copy()
  current = 1
  valid = True
  for next_pos in route:
    if ([current, next_pos] in cur_path):
      cur_path.remove([current, next_pos])
      current = next_pos
      continue
    elif ([next_pos, current] in cur_path):
      cur_path.remove([next_pos, current])
      current = next_pos
      continue
    else:
      valid = False
      break
  
  if(valid == True):
    count += 1

print(count)