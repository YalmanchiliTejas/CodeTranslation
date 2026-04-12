r,g,b = [int(i) for i in input().split()]

s = 100*r + 10*g + b

if s%4 == 0:
    print('YES')
else:
    print('NO')
