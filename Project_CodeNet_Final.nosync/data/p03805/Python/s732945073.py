import itertools
n,m=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(m)]

path=[[] for _ in range(n)]
for a,b in AB:
  path[a-1].append(b-1)
  path[b-1].append(a-1)

ans=0
for ptn in itertools.permutations(range(1,n)):
  start=0
  for nex in ptn:
    if start not in path[nex]: break
    start=nex
  else:
    ans+=1
print(ans)