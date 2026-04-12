H,W=map(int,input().split())
A=[input() for i in range(H)]

B=[]
D=[]

for i in range(H):
  if A[i]!="."*W:
    B.append(list(A[i]))
    
C=[["0" for j in range(len(B))] for i in range(W)]

for i in range(len(B)):
  for j in range(W):
    C[j][i]=B[i][j]

for i in range(W):
  if C[i]!=["."]*len(B):
    D.append(C[i])
   
E=[["0" for j in range(len(D))] for i in range(len(B))]

for i in range(len(D)):
  for j in range(len(B)):
    E[j][i]=D[i][j]
    
for i in range(len(B)):
  print("".join(E[i]))

