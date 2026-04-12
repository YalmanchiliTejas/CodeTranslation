# input
r, g, b = [i for i in input().split()]

n = int(r + g + b)

if n%4==0:
    print('YES')
else:
    print('NO')        