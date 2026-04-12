r,g,b = map(int,input().split())

total = r*100 + g * 10 + b

if(total%4 == 0):
    print('YES')
else:
    print('NO')