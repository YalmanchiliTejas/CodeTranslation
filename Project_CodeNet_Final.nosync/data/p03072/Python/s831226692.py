n=int(input())
h=list(map(int,input().split()))
x=0
y=0
z=0
for x in range(n):
  if h[x]>=y:
    z+=1
    y=h[x]
print(z)