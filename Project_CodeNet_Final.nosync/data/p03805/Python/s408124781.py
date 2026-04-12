from itertools import permutations
N, M, *L = map(int, open(0).read().split())
dic = [[] for i in range(N+1)]
for a, b in zip(*[iter(L)]*2):
  dic[a].append(b)
  dic[b].append(a)

ans = 0
for l in permutations(range(2,N+1)):
  l = [1]+list(l)
  for i in range(N-1):
    if l[i+1] not in dic[l[i]]:
      break
  else:
    ans += 1
print(ans)