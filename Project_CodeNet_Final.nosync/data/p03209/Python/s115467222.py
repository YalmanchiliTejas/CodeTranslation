n,x = map(int,input().split())

a=[0]*n
p=[0]*n

a[0]=1
p[0]=1

for i in range(1,n):
  a[i]=3+2*a[i-1]
  p[i]=1+2*p[i-1]
  
def f(n,x):
  if n ==0:
    return 0 if x <= 0 else 1
  elif x <= 1+a[n-1]:
    return f(n-1,x-1)
  else:
    return p[n-1]+1+f(n-1,x-a[n-1]-2)

print(f(n,x))

