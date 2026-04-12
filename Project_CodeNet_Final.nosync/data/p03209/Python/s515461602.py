n,x=map(int,input().split())
def b(n,x):
  if n==0 and x==1:
    return 1
  while n>0:
    z=(2**(n+2)-3)//2+1
    if x==1:
      return 0
    elif 1<x<z:
      return b(n-1,x-1)
    elif x==z:
      return 2**n
    elif z<x<(2**(n+2)-3):
      return 2**n + b(n-1,x-z)
    else:
      return 2**(n+1)-1
print(b(n,x))