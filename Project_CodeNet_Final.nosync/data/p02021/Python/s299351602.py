n=int(input())
a=[int(x) for x in input().split()] 
x=100
for i in range(n):
  x=min(x,sum(a[:i+1])//(i+1))
print(x)
