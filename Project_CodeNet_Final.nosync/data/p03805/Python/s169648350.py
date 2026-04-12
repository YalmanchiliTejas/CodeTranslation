import itertools

N,M = map(int,input().split())
lis = [x+1 for x in range(N-1)]
path = [list(map(int, input().split())) for _ in range(M)]
pb = [[False] * N for i in range(N)]
for i in range(M):
  p = path[i][0]-1
  q = path[i][1]-1
  pb[p][q] = True
  pb[q][p] = True

c = 0
for ps in itertools.permutations(lis):
  if pb[0][ps[0]]:
    for i in range(N-2):
      if not pb[ps[i]][ps[i+1]]:
        break
    else:
      c += 1

print(c)