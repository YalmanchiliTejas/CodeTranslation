import itertools
N, M = map(int, input().split())
d = [[] for i in range(N)]
for i in range(M):
  a, b = map(int, input().split())
  d[a-1].append(b-1)
  d[b-1].append(a-1)

r = 0
for path in itertools.permutations(range(1, N)):
  path = tuple([0]) + path
  for i in range(1, N):
    if(path[i] not in d[path[i-1]]):
      break
  else:
    r += 1
print(r)