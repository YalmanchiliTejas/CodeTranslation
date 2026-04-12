#制約が小さいので全探索する
n,m=list(map(int,input().split()))
#辺があるかどうかが知りたい→隣接行列表現
es=[[0]*n for i in range(n)]
for i in range(m):
  a,b=list(map(int,input().split()))
  es[a-1][b-1]=1
  es[b-1][a-1]=1

#順列を作る
from itertools import permutations
per=[i+1 for i in range(n-1)]
per=list(permutations(per,n-1))

#全探索する
ans=0
for i in per:
  cnt=0
  if es[0][i[0]]==0:
    continue
  else:
    for j in range(1,n-1):
      if es[i[j]][i[j-1]]==0:
        cnt+=1
    if cnt==0:
      ans=ans+1
print(ans)

