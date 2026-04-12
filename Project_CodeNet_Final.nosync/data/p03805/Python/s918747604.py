N, M =list(map(int, input().split()))
AB = [list(map(int, input().split())) for _ in range(M)]

memo={}
for a,b in AB:
  #print(a,b)
  memo.setdefault(a, set([])).add(b)
  memo.setdefault(b, set([])).add(a)

answer=0
from itertools import permutations
for p in permutations(list(range(2,N+1))):
  if p[0] not in memo[1]:
    continue
  for i in range(N-2):
    if p[i+1] in memo[p[i]]:
      pass
    else:
      break
  else:
    answer+=1
      
print(answer)                  