r,g,b = map(int,input().split())
i = ((r * 100) + (g * 10) + b) % 4
if i == 0:
    print('YES')
else:
    print('NO')