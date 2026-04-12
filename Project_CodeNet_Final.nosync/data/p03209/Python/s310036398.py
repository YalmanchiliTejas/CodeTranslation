n,x=map(int,input().split())
p=[1]
a=[1]
for i in range(0,n):
  p.append(p[i]*2+1)
  a.append(a[i]*2+3)
def f(n,x):
  if n==0 and x<=0:
    return 0
  elif n==0:
    return 1
  elif x<=1+a[n-1]:
    return f(n-1,x-1)
  else:
    return p[n-1]+f(n-1,x-a[n-1]-2)+1
print(f(n,x))