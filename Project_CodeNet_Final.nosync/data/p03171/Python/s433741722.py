N=int(input())
a=list(map(int,input().split()))
ans=[[0 for e in range(N+1)] for f in range(N+1)]
for j in range(1,N+1):
 ans[j][1]=a[j-1]
if N>1:
 for i in  range(2,N+1):
  for j in range(1,N+2-i):
   ans[j][i]=max(a[j-1]-ans[j+1][i-1],a[j+i-2]-ans[j][i-1])
print(ans[1][N])
