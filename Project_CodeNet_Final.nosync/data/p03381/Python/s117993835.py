n=int(input())
x=list(map(int,input().split()))
a=[]
for i in range(n):
  a+=[(x[i],i)]
a=sorted(a)
ans=[]
for i in range(n):
  if i<n//2:ans+=[(a[i][1],a[n//2][0])]
  else:ans+=[(a[i][1],a[n//2-1][0])]
for i,j in sorted(ans):
  print(j)