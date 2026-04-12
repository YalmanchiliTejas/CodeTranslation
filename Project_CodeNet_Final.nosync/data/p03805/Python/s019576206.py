from collections import defaultdict
from itertools import permutations
N, M = map(int, input().split())
dic = defaultdict(list)
for i in range(M):
  a, b = map(int, input().split())
  dic[a-1] += [b-1]
  dic[b-1] += [a-1]

ans = 0
ls = permutations(range(1,N))
for l in ls:
  l = [0]+list(l)
  for i in range(N-1):
    if not l[i+1] in dic[l[i]]:
      break
    if i==N-2:
      ans += 1
print(ans)