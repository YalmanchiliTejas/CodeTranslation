H,W=map(int,input().split())

A = [list(input()) for i in range(H)]

l=[False]*H
c=[False]*W

for i in range(H):
  for j in range(W):
    if A[i][j]=='#':
      l[i]=True
      c[j]=True

ans=['' for i in range(H)]
for i in range(H):
  for j in range(W):
    if l[i] and c[j]:
      ans[i]+=A[i][j]
for i in range(H):
  if str(ans[i])!='':
    print(str(ans[i]))