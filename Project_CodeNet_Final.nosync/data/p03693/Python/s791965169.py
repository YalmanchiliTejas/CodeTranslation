r,g,b=input().split()
r=int(r)
g=int(g)
b=int(b)
x=100*r+10*g+b
if x%4==0:
    print('YES')
else:
    print('NO')