H,W=map(int,input().split())
S=[list(input()) for _ in range(H)]
A=[False]*H
B=[False]*W
for i in range(H):
  for j in range(W):
    if S[i][j]=='#':
      A[i]=True
      B[j]=True

for i in range(H):
  if A[i]:
    for j in range(W):
      if B[j]:
        print(S[i][j], end = '')
    print()