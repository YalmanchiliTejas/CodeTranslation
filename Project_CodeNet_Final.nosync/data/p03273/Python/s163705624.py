H,W=map(int,input().split())
A=[list(input()) for i in range(H)]
B=[]
C=[]
ans=[]
for i in range(H):
  if '#' in A[i]:
    B.append(A[i])
C=list(zip(*B))
for i in range(W):
  if '#' in C[i]:
    ans.append(C[i])
ans=list(zip(*ans))
for k in range(len(ans)):
  print(*ans[k],sep='')