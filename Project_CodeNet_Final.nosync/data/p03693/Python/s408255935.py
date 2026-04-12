a=input()
a=a.split()

r=int(a[0])
g=int(a[1])
b=int(a[2])

x=100*r+10*g+b

if(x%4==0):
    print('YES')
else:
    print('NO')