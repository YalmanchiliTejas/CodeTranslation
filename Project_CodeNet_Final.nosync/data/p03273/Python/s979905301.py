H,W=map(int,input().split())
A=[]
for i in range(H):
  a=input()
  A.append(a)
aw_h=[]
aw_v=[]
for i in range(H):
  if '#' not in A[i]:
    aw_h.append(i)
for i in range(len(aw_h)):
  A.pop(aw_h[i]-i)
for i in range(W):
  count=0
  for j in range(len(A)):
    if A[j][i]=='.':
      count+=1
  if count==len(A):
    aw_v.append(i)
for i in range(len(A)):
  for j in range(len(aw_v)):
    A[i]=A[i][:aw_v[j]-j]+A[i][aw_v[j]-j+1:]
for i in range(len(A)):
  print(str(A[i]))