num = input().split()
r, g, b = num

color = int(r+g+b)

if(color%4 == 0):
    print('YES')
else:
    print('NO')