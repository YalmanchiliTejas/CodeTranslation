n,x,m=map(int,input().split())
A=[[0]*2 for i in range(m)]
A[x]=[1,x]
a=x
f=-1
for i in range(10**5+100):
  if i==n-1:
    f=0
    break
  x=x**2%m
  a=a+x
  if A[x][0]!=0:
    f=1
    break
  A[x]=[i+2,a]
if f==0:
  print(a)
elif f==1:
  ans=A[x][1]+(a-A[x][1])*((n-A[x][0])//(i+2-A[x][0]))
  for i in range((n-A[x][0])%(i+2-A[x][0])):
    x=x**2%m
    ans=ans+x
  print(ans)