H, W=map(int, input().split())
A=[]
tate=[False]*W
for i in range(H):
  tmp=list(input())
  if "#" not in tmp:
    continue
  A.append(tmp)
  for j in range(W):
    if tmp[j]=="#":
      tate[j]=True

for i in range(len(A)):
  ans=[]
  for j in range(W):
    if tate[j]:
      ans.append(A[i][j])
  print("".join(ans))
  
  