import itertools
n,m=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(m)]

path=[[] for _ in range(n)]
for a,b in AB:
  a,b=a-1,b-1
  path[a].append(b)
  path[b].append(a)
ans=0
for ptn in itertools.permutations(range(1,n)):
  s=0
  for nex in ptn:
    if s not in path[nex]: break
    s=nex
  else:
    ans+=1
print(ans)