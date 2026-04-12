N, X=map(int, input().split())
W=[0]*51
W[0]=1
for i in range(1,51):
  W[i]=W[i-1]*2 + 3
  
P=[0]*51
P[0]=1
for i in range(1,51):
  P[i]=P[i-1]*2+1
#nバーガーのX番目までのP  
def burger(n,x):
  if n==0:
    return 1
  #n-1バーガーの長さ
  l=W[n-1]
  if x==1:
    return 0
  if x==W[n]:
    return P[n]
  if x==1+l+1:
    return P[n-1]+1
  if 1<x<=l+1:
    return burger(n-1,x-1)
  if 1+l+1<x<=1+l+1+l:
    return P[n-1]+1+burger(n-1,x-(l+2))
  
print(burger(N, X))

