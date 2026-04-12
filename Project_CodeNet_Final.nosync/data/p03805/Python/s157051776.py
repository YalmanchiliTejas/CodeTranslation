from itertools import permutations
N,M = list(map(int,input().split()))
e = [list(map(int,input().split())) for i in range(M)]
a = 0

for p in permutations(range(1,N+1)):
  f = True
  if p[0]==1:
    for i in range(N-1):
      if sorted([p[i],p[i+1]]) not in e:
        f = False
    if f:
      a+=1

print(a)