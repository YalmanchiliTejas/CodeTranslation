r,g,b,=input().split()
r=int(r)
g=int(g)
b=int(b)

if ((r*100)+(g*10)+b)%4==0:
  print('YES')
else:
  print('NO')