import itertools
N,M = map(int,input().split())
edges = set()
for _ in range(M):
  a,b = map(int,input().split())
  edges.add((a,b))
  edges.add((b,a))

answer = 0

for p in itertools.permutations(range(1,N+1)):
  if p[0] != 1:
    continue
  bl = True
  for i in range(N-1):
    if (p[i], p[i+1]) not in edges:
      bl = False
      break
  if bl:
    answer += 1

print(answer)