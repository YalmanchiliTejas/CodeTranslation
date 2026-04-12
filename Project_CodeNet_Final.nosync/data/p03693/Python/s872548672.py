x=input()
y=int(x.split()[0]+x.split()[1]+x.split()[2])
if y%4==0:
    print('YES')
else:
    print('NO')