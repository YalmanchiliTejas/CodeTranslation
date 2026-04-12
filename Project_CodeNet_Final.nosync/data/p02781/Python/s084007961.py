N=input()
n=int(N)
K=int(input())
import math

l=len(N)

if l==1:
  if K==1:
    print(N)
  else:
    print(0)
else:
  a=[0]*3
  b=[l]*3
  k=0
  for i in range(l):
    if int(N[i])!=0:
      a[k]=int(N[i])
      b[k]=i
      k+=1
    if k==3:
      break
  #print(a,b,l)
  x=0
  for i in range(l-1):
    if K==1:
      x+=9
    elif K==2:
      x+=81*i
    else:
      x+=(729*i*(i-1))//2
  
  if K==1:
    x+=a[0]
  elif K==2:
    x+=(a[0]-1)*9*(l-1)+max([0,(l-b[1]-1)*9])+a[1]
  else:
    x+=((a[0]-1)*81*(l-2)*(l-1))//2
    x+=(81*max([0,(l-b[1]-1)])*max([0,(l-b[1]-2)]))//2
    x+=max([0,(a[1]-1)])*9*max([0,(l-b[1]-1)])
    x+=9*max([0,(l-b[2]-1)])+a[2]
  
  print(x)