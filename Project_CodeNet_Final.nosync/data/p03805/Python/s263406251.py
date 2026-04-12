import itertools

N, M = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(M)]

count = 0
for path in itertools.permutations([i for i in range(2, N+1)], N-1):
  flag = True
  if [1, path[0]] in ab or [path[0], 1] in ab:
    pass
  else:
    flag = False
    continue
  for i in range(1, N):
    if flag:
      if i == N-1:
        count += 1
        continue
      if [path[i-1], path[i]] in ab or [path[i], path[i-1]] in ab:
        continue
      else:
        flag = False
print(count)
