from itertools import *
N,M = map(int,input().split())
S = [list(map(int,input().split())) for m in range(M)]
a = 0

for p in permutations(range(1,N+1)):
  f = True
  if p[0]==1:
    for n in range(N-1):
      if sorted([p[n],p[n+1]]) not in S:
        f = False
    if f:
      a+=1

print(a)