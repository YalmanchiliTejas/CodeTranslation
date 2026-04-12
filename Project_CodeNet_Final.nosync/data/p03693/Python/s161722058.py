r, g, b = [int(i) for i in input().split()]
n = r*100 + g*10 + b
if n % 4:
    print('NO')
else:
    print('YES')