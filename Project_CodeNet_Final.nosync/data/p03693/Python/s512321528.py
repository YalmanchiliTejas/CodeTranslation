r, g, b =list(input().split())
sum = int(r + g + b)
if sum%4 == 0:
    print('YES')
else:
    print('NO')