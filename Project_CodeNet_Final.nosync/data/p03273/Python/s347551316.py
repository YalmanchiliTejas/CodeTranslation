H,W=map(int,input().split())
A=[]
for i in range(H):
  a=list(input())
  if a != ["."]*W:
    A.append(a)
f = []
for i in range(W):
  flag=1
  for j in range(len(A)):
    if A[j][i]=="#":
      flag=0
      break
  if flag:
    f.append(i)
for i in range(len(A)):
  for j in range(W):
    if j not in f:
      print(A[i][j],end="")
  print()