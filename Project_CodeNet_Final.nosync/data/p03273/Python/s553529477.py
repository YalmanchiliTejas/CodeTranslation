h,w=map(int,input().split())

L=[]
for i in range(h):
  a=list(input())
  if "#" in a:
    L.append(a)
import numpy as np
A=[]
tenti=np.array(L).T
for i in range(w):
  if "#" in tenti[i]:
    A.append(tenti[i])
tenti=np.array(A).T 
ans=""

for i in range(len(tenti)):
  for j in range(len(tenti[i])):
    ans+=tenti[i][j]
  print(ans)
  ans=""

