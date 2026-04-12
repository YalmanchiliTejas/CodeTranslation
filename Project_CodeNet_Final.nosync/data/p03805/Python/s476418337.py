from itertools import permutations

N, M = map(int, input().split())
paths = [list(map(int, input().split())) for _ in range(M)]

points = [i for i in range(1, N+1)]
answer = 0

for point in permutations(points):
  if not point[0] == 1:
    continue
  for i in range(N-1):
    if sorted([point[i], point[i+1]]) not in paths:
      break
  else:
    answer += 1

print(answer)
