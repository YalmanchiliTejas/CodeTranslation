import itertools
N,M=map(int,input().split())
ki=[[]for i in range(N)]
for i in range(M):
 a,b=map(int,input().split())
 ki[a-1].append(b-1)
 ki[b-1].append(a-1)
ans=0
for v in itertools.permutations(range(1,N), N-1):
 path=0
 if v[0] in ki[0]:
  path+=1
 if N>2:
  for i in range(N-2):
   if v[i+1] in ki[v[i]]:
    path+=1
 if path==N-1:
  ans+=1
print(ans)