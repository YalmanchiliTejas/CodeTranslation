x = input()
y = x.split()
r = int(y[0])
g = int(y[1])
b = int(y[2])
A = 100*r+10*g+b
if A%4 == 0:
    print('YES')
else:
    print('NO')