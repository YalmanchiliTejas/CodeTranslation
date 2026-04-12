g=1
y=0
a=int(input())
b=list(input().split())
h=int(b[0])
for i in range(1,a):
  if int(b[i-1])<=int(b[i]) and h<=int(b[i]) and y<=int(b[i]):
    y=int(b[i])
    g+=1
print(g)