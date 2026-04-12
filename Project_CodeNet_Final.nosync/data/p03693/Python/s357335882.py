r, g, b = input().split()
card = int(r + g + b)
if card % 4:
    print('NO')
else:
    print('YES')
    