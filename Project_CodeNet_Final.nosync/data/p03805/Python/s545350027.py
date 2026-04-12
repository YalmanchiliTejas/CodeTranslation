from itertools import permutations
N,M=map(int,input().split())
l=[[] for _ in range(N)]
for _ in range(M):
  x,y=map(int,input().split())
  l[x-1].append(y-1)
  l[y-1].append(x-1)

res=0
for i in permutations(range(2,N+1)):
  s='1'
  for j in i:
    s+=str(j)
  ans=True
  for k in range(N-1):
    ss=int(s[k])-1
    st=int(s[k+1])-1
    if st not in l[ss]:
      ans=False
  if ans:
    res+=1
print(res)