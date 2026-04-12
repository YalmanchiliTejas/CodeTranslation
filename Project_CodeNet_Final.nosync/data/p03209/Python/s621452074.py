n,x=map(int,input().split())
def f(n,x):
  if n==1:
    return 0 if x==1 else 1 if x==2 else 2 if x==3 else 3
  else:
    if x==1:
      return 0
    elif x<=2**(n+1)-2:
      return f(n-1,x-1)
    elif x==2**(n+1)-1:
      return 2**n
    elif x<=2**(n+2)-4:
      return 2**n+f(n-1,x-2**(n+1)+1)
    else:
      return 2**(n+1)-1
print(f(n,x))