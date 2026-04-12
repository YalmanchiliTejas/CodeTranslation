from itertools import permutations
n,m=map(int,input().split())
e=[[]for _ in range(n)]
for _ in range(m):
  a,b=map(int,input().split())
  e[a-1]+=[b-1]
  e[b-1]+=[a-1]
num=list(permutations([0]+list(range(1,n))))
ans=0
for i in range(len(num)):
  if num[i][0]!=0:continue
  s=1
  now=0
  while s<n:
    if num[i][s] in e[now]:
      now=num[i][s]
      s+=1
    else:break
  if s==n:ans+=1
print(ans)