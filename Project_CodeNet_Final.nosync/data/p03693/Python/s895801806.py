r, g, b = input().split()
if not int(r+g+b) % 4:
    print('YES')
else:
    print('NO')
