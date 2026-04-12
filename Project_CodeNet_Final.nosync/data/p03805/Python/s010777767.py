import itertools

N,M = map(int,input().split())
l = [ i for i in range(2,N+1)]

dist = {i:[] for i in range(1,N+1)}

for i in range(M):
  a,b = map(int,input().split())
  dist[a].append(b)
  dist[b].append(a)  

cnt = 0

for v in itertools.permutations(l):
  a = 1  
  for v1 in v:
    if a in  dist.get(v1):
      a = v1
      if a == v[-1]:
        cnt += 1
      continue
    else:
      break

print(int(cnt))