N, X, M = map(int, input().split())
list=[0]*M
X1=X
for i in range(M):
  list[i]=(i**2)%M
  
l=[0]*M
l[X]=1
while l[list[X]]==0:
  l[list[X]]+=1
  X=list[X]
while l[list[X]]==1:
  l[list[X]]+=1
  X=list[X]
  
n1=l.count(1)
n2=l.count(2)

loop1=[0]*n1
for i in range(n1):
    loop1[i]+=X1
    X1=list[X1]
    
loop2=[0]*n2
for i in range(n2):
    loop2[i]+=X1
    X1=list[X1]
        
if N<=n1:
  print(sum(loop1[:N]))
else:
  print(sum(loop1)+(N-n1)//n2*sum(loop2)+sum(loop2[:(N-n1)%n2]))