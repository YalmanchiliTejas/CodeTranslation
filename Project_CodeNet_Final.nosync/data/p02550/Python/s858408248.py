N,X,M=map(int,input().split())
A=[0 for i in range(10**5)]
A[X]=1
c=[]
d=[]
now=X
for i in range(2,N+1):
  now=now**2%M
  if A[now]==0:
    A[now]=i
  else:
    s=A[now]
    p=i-s
    cycle=[0 for i in range(p)]
    f=[]
    for j in range(10**5):
      if s<=A[j]<i:
        cycle[A[j]-s]=j
      if A[j]<s and A[j]!=0:
        f.append(j)
    c=cycle
    d=f
    break
if c==[]:
  ans=0
  for i in range(len(A)):
    if A[i]!=0:
      ans+=i
  print(ans)
else:
  x=len(d)
  y=len(c)
  ccount=(N-x)//y
  amari=(N-x)%y
  ans=sum(d)+sum(c)*ccount+sum(c[:amari])
  print(ans)
