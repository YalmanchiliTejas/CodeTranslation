r, g, b = input().split(' ',3)
if (int(r + g + b) % 4== 0) :
    print('YES')
else:
    print('NO')  