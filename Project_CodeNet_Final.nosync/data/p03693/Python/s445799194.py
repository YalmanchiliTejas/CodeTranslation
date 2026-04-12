cores=input().split()
r,g,b=int(cores[0]), int(cores[1]), int(cores[2])
numero=(r*100)+(g*10)+(b)
if numero%4==0:
    print('YES')
else:
    print('NO')