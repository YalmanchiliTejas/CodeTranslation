r, g, b = map(int,input().split())
soma = 0

if 1 <= r <= 9 and 1 <= g <= 9 and 1 <= b <= 9:
    soma = r*100 + g*10 + b
    if soma%4 == 0:
        print('YES')
    else:
        print('NO')

