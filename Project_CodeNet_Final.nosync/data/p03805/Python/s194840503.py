from itertools import permutations
N, M = map(int, input().split())
table = [[] for i in range(N)]
for i in range(M):
  a,b = map(int, input().split())
  a -= 1
  b -= 1
  table[a].append(b)
  table[b].append(a)
  
numbers = [i for i in range(1,N)]
P = list(permutations(numbers,N-1))
ans = 0

for p in P:
  if p[0] in table[0]:
    for i in range(N-2):
      if p[i+1] not in table[p[i]]:
        break
    else:
      ans += 1  
print(ans)