n,x=map(int,input().split())

def f(n,x):
  if n==0:
    if x>0:return 1
    else:return 0
  if x<=(2**(n+2)-3-1)//2:
    return f(n-1,x-1)
  else:
    tmp=x-((2**(n+2)-3-1)//2+1)
    return 2**n-1+1+f(n-1,tmp)
  
print(f(n,x))
