N,M=map(int,input().split())
Edge=[[int(i) for i in input().split()] for i in range(M)]
Vertex=[]
X=[]
n=1
a=0
while n<=N:
  while a<=M-1:
    if n in Edge[a]:
      X=X+Edge[a]
    a+=1
  X=[item for item in X if item!=n]
  Vertex.append(X)
  n+=1
  a=0
  X=[]
Choices=[[1]]
m=0
for i in Choices:
    if len(i)>=N:
      break
    for j in Vertex[i[len(i)-1]-1]:
      Choices.append(i+[j])
Choices=[item for item in Choices if len(item)==N]
a=1
while a<=N:
  Choices=[item for item in Choices if item.count(a)==1]
  a+=1
print(len(Choices))
      
    