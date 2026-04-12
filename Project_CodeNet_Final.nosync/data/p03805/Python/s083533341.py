import itertools
import math
N, M = map(int, input().split())
a = []
ans = 0
for _ in range(M):
  a.append(set(map(int, input().split())))
for ind in itertools.permutations([i for i in range(N)]):
  if ind[0] != 0:
    break
  flag = True
  for i in range(N):
    if i == N-1:
      break
    if not(set([ind[i]+1, ind[i+1]+1]) in a):
      flag = False
  if flag:
    ans += 1
print(ans)