import sys
sys.setrecursionlimit(10**7)
n,x=map(int,input().split())
l=[0]*(n+1)
c=[0]*(n+1)
c[0]=l[0]=1
for i in range(1,n+1):
  l[i]=l[i-1]*2+3
  c[i]=c[i-1]*2+1
def check(r,t):
  if r==0 and t>0:
    return 1
  elif r==0:
    return 0
  elif t<=l[r-1]+1:
    return check(r-1,t-1)
  else:
    return check(r-1,t-l[r-1]-2)+c[r-1]+1
print(check(n,x))