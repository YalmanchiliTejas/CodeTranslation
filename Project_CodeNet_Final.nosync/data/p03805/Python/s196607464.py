N,M=map(int,input().split())
R=list(list(map(int,input().split())) for _ in range(M))
S=[i for i in range(2,N+1)]

import itertools
count=0
for p in itertools.permutations(S):
  damage=0
  p=list(p)
  q=[1]
  for j in range(N-1):
    q.append(p[j])
  for i in range(N-1):
    if not([q[i],q[i+1]] in R) and not([q[i+1],q[i]] in R):
      damage=1
  if not(damage):
    count+=1


print(count)
