N, M = map(int, input().split())
L = [tuple(map(int, input().split())) for _ in range(M)]
import itertools
l = [i for i in range(2, N+1)]
Ps = itertools.permutations(l, N-1)
c = 0
for P in Ps:
  T = 1
  for p in P:
    if (T, p) in L or (p, T) in L:
      T = p
    else:
      break
  else:
    c += 1
print(c)