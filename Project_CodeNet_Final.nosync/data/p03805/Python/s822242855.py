import itertools

N,M=map(int,input().split())
C=[[] for j in range(N)]
for i in range(M):
  a,b=map(int,input().split())
  C[a-1].append(b-1)
  C[b-1].append(a-1)

d=[int(x)+1 for x in range(N-1)]
ans=0
for exam in itertools.permutations(d):
  cnt=list(exam)
  cnt.insert(0,0)
  flg=True
  for i in range(N-1):
    if not(cnt[i+1] in C[cnt[i]]):
      flg=False
      break
  if flg:
    ans+=1
print(ans)