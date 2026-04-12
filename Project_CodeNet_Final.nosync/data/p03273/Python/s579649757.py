H,W=map(int,input().split())
A=[list(input()) for i in range(H)]

for i in reversed(range(H)):
  if A[i]==["."]*W:
    A.pop(i)
    
for j in reversed(range(W)):
  flag=0
  for i in range(len(A)):
    if A[i][j]=="#":
      flag=1
  if flag==0:
    for i in range(len(A)):
      A[i].pop(j)

for i in range(len(A)):
	print("".join(A[i]))