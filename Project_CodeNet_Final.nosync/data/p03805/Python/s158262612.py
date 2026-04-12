from itertools import *
N,M=map(int,input().split())
X=list(permutations(list(range(2,N+1))))
P=0
a,b=0,0
S=set()
for i in range(M):
  a,b=map(int,input().split())
  S.add((a,b))
  S.add((b,a))
for i in range(len(X)):
  for j in range(N-1):
    if not(((1 if j==0 else X[i][j-1]),X[i][j]) in S):
      break
    if j==N-2:
      P+=1
print(P)