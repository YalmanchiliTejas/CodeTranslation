import itertools

n,m=list(map(int,input().split()))
path=[[False]*n for _ in range(n)]
for i in range(m):
  a,b=list(map(int,input().split()))
  path[a-1][b-1]=True

ans=0
for i in itertools.permutations(list(range(n))):
  if i[0]!=0:
    continue
  flg=True
  for j in range(len(i)-1):
    if path[min(i[j],i[j+1])][max(i[j],i[j+1])]==False:
      flg=False
      break
  if flg:
    ans+=1
print(ans)