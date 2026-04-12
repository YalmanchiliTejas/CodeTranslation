X=[]
X=map(int,input().split(' '))
map(str,X)
Y=int(''.join(map(str,X)))
if Y%4==0:
    print('YES')
else:
    print('NO')
