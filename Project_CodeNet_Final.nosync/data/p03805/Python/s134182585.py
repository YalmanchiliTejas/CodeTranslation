import itertools
N, M = map(int, input().split())

I = [set() for _ in range(N)]
seq = [i for i in range(1,N)]

for _ in range(M):
  a, b = map(int, input().split())
  I[a-1].add(b-1)
  I[b-1].add(a-1)

ans = 0
for p in itertools.permutations(seq):
  flag = True
  for i in range(N-2):
    #print(p,i)
    if p[i+1] not in I[p[i]]:
      flag = False 
      break
  if 0 not in I[p[-1]]:#0を終点とする
    flag = False 
  if flag:
    ans += 1
#print(I)    
print(ans)
    