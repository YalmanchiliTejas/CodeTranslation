N=int(input())
A=[int(input()) for i in range(N)]
import bisect
B=[]
C=A[::-1]
for i in C:
  a=bisect.bisect_right(B,i)
  if a==len(B):
    B.append(i)
  else:
    B[a]=i
print(len(B))