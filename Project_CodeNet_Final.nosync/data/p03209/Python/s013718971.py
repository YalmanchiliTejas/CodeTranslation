N,X=map(int,input().split())
a=[[]]*(N+1)
b=[[]]*(N+1)
ans=N
for i in range(N+1):
  a[i]=pow(2,i+1)-1
  b[i]=pow(2,i+2)-3

def f(n,x):
  if n==0:
    if x<=0:return 0
    else:return 1
  else:
    if x==1:
      return 0
    elif 1<x<=1+b[n-1]:
      return f(n-1,x-1)
    elif x==2+b[n-1]:
      return a[n-1]+1
    elif 2+b[n-1]<x<=2+2*b[n-1]:
      return f(n-1,x-2-b[n-1])+a[n-1]+1
    else:
      return 2*a[n-1]+1
print(f(N,X))