rgb = input().split()

rgb = ''.join(rgb)

if int(rgb) % 4 == 0:
    print('YES')
else :
    print('NO')