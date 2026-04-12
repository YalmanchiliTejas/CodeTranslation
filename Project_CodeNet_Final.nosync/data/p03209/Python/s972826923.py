n,x=map(int,input().split())
c=0
def p(n):
  return 2*(2**n)-1
def f(n):
  return 4*(2**n)-3

c=0
for i in range(n,0,-1):
  if x:
    x-=1
  if x>=f(i-1):
    x-=f(i-1)
    c+=p(i-1)
    if x:
      x-=1
      c+=1
      if x>=f(i-1):
        x-=f(i-1)
        c+=p(i-1)
        if x:
          x-=1
print(c)