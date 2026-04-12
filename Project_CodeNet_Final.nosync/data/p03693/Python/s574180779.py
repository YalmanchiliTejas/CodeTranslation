r,g,b = input().split()

t = int(r+g+b)

if t % 4 == 0:
    print('YES')
else:
    print('NO')