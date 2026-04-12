H,W=map(int,input().split())
A=[input() for x in range(H)]

ans=[]

for i in range(H):
  ch=False
  for j in range(W):
    if A[i][j]=='#':
      ch=True
      break
  if ch:
    ans.append(A[i])

ans=list(zip(*ans))
ans1=[]

for i in range(W):
  ch=False
  for j in range(len(ans[i])):
    if ans[i][j]=='#':
      ch=True
      break
  if ch:
    ans1.append(ans[i])
    
ans1=list(zip(*ans1))

for i in range(len(ans1)):
  print("".join(list(ans1[i])))
