import itertools
n,m=map(int,input().split())
path=[[] for i in range(n)]
for i in range(m):
  a,b=map(int,input().split())
  path[a-1].append(b-1)
  path[b-1].append(a-1)

res = 0
for case in itertools.permutations(range(n)):
  if case[0] != 0:
    continue
  for i in range(n-1):
    if case[i+1] not in path[case[i]]:
      break
  else:
    res+=1
print(res)