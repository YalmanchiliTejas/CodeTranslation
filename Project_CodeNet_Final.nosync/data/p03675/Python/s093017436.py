n=int(input())
m=n
a=list(map(int,input().split()))
if(m%2==0):
  while(n>=4):
    print(str(a[n-1])+' ',end="")
    n-=2
  print(str(a[1])+' ',end="")
  n=1
  while(n!=m-1):
    print(str(a[n-1])+' ',end="")
    n+=2
  print(a[m-2])
else:
  if(m==1):
    print(a[0])
  else:
    while(n>=3):
      print(str(a[n-1])+' ',end="")
      n-=2
    print(str(a[0])+' ',end="")
    n=2
    while(n!=m-1):
      print(str(a[n-1])+' ',end="")
      n+=2
    print(a[m-2])