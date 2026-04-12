R,G,B=input().split()
r=int(R)
g=int(G)
b=int(B)
x=100*r
y=10*g
z=b
p=x+y+z
if p%4==0:
  print('YES')
else:
  print('NO')