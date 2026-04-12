def c(n, x):
  if n==0:
    return 1
  s=0
  if x==1:
    return 0
  elif 1<x<=1+l[n-1]:
    return c(n-1,x-1)
  elif x==2+l[n-1]:
    return c(n-1,x-1)+1
  else:
    return p[n-1]+1+c(n-1,x-l[n-1]-2)

N, X = map(int, raw_input().split())
l = [0]*(N+1)
l[0]=1
p = [0]*(N+1)
p[0]=1
for i in range(1, N+1):
  l[i] = 2*l[i-1]+3
  p[i] = 2*p[i-1]+1
a = c(N,X)
print a