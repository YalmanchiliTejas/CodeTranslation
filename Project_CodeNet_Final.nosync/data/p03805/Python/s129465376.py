import itertools
n,m=map(int,input().split())
l=[list(map(int,input().split())) for i in range(m)]
L=list(itertools.permutations(range(2,n+1)))
c=0
for j in range(len(L)):
  if [1,L[j][0]] in l:
    x=0
    for k in range(n-2):
      if [L[j][k],L[j][k+1]] in l or [L[j][k+1],L[j][k]] in l:x+=1
    if x==n-2:c+=1
print(c)