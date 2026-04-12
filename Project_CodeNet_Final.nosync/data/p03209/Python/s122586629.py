n,x=map(int,input().split())
A=[0]*51
B=[0]*51
A[0]=1
B[0]=1
i=1
while i<=50:
  A[i]=A[i-1]*2+3
  B[i]=B[i-1]*2+1
  i=i+1
#print(A)
#print(A[50])
#print(B[50])
ans=0
if n>=2:
  for i in range(n-1,0,-1):
    #print(i)
    if x==1 or x==0:
      break
    elif 1<x and x<=1+A[i]:
      x=x-1
    elif x==2+A[i]:
      ans=ans+B[i]+1
      break
    elif 2+A[i]<x and x<A[i+1]:
      ans=ans+B[i]+1
      x=x-A[i]-2
    else:
      ans=ans+2*B[i]+1
      break
    if i==1:
      if x==2:
        ans=ans+1
      elif x==3:
        ans=ans+2
      elif x==4 or x==5:
        ans=ans+3
  print(ans)
else:
  if x==1:
    print(0)
  elif x==2:
    print(1)
  elif x==3:
    print(2)
  elif x==4:
    print(3)
  elif x==5:
    print(3)