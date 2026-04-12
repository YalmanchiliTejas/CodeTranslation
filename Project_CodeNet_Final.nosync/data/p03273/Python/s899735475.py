H,W=map(int,input().split())
A=[list(input()) for i in range(H)]
a=0
for i in range(H):
  if set(A[i-a])==set(['.']):
    del A[i-a]
    a+=1
b=0
for i in range(W):
  for j in range(H-a):
    if A[j][i-b]=='#':
      break
    if j==H-a-1:
      for k in range(H-a):
        del A[k][i-b]
      b+=1
for i in range(len(A)):
  print(''.join(A[i]))