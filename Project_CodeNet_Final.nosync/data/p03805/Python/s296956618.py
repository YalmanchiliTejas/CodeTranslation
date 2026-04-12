import itertools
n,m=map(int,input().split())
A=[]
for i in range(m):
  a,b=map(int,input().split())
  A.append([a,b])
N=[int(i+2) for i in range(n-1)]
def f(list,n):
  path=0
  if [1,list[0]] in A:
    path+=1
  for i in range(1,n-1):
    if [list[i],list[i-1]] in A or [list[i-1],list[i]] in A:
      path+=1
  if path==n-1:
    return 1
  else:
    return 0  
ans=0
for p in itertools.permutations(N,n-1):
  ans+=f(list(p),n)
print(ans)