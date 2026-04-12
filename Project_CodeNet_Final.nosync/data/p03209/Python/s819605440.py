def a(n):
  return 2**(n+2)-3
def b(n):
  return 2**(n+1)-1
N,X= [int(s) for s in input().split()]
count=0
while X>0:
  if X==a(N):
    count+=b(N)
    X-=a(N)
  elif X<a(N):
    X-=1
    N-=1
  else:
    X-=a(N)+1
    count+=b(N)+1
print(count)