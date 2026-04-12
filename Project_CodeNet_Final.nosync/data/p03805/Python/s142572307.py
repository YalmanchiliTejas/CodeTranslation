import itertools
n,m=map(int,input().split())
node=[[0 for i in range(n)] for j in range(n)]
for i in range(m):
  a,b=[int(x)-1 for x in input().split()]
  node[a][b]=1
  node[b][a]=1
ct=0
for order in itertools.permutations(range(n),n):
  if order[0]==0:
    for j in range(n):
      if j==n-1:
        ct+=1
        break
      if not node[order[j]][order[j+1]]:
        break
    
print(ct)