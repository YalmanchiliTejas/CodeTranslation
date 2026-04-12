from collections import deque
n=int(input())
E=[[] for i in range(n)]
for i in range(n-1):
  a,b=map(int,input().split())
  a=a-1
  b=b-1
  E[a].append(b)
  E[b].append(a)
D=deque([0])
V=[0]*n
V[0]=1
A=[0]
P=[-1]*n
while len(D)>0:
  x=D[0]
  D.popleft()
  for c in E[x]:
    if V[c]==0:
      D.append(c)
      A.append(c)
      P[c]=x
      V[c]=1
A=A[::-1]
VV=[0]*n
f=0
for c in A:
  if VV[c]==0:
    if P[c]==-1 or VV[P[c]]==1:
      f=1
    else:
      VV[c]=1
      VV[P[c]]=1
if f==1:
  print("First")
else:
  print("Second")