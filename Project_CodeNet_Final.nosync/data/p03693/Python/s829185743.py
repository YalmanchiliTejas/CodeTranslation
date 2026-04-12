r, g, b = input().split()

num = int(r + g + b)
rem = num % 4

if rem == 0:
    print('YES')
else:
    print('NO')