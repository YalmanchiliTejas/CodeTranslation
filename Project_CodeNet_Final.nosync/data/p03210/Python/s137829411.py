year = int(input())

if year < 1 or 9 < year:
    raise ValueError('Input value must be less than 9 and more than 1')
elif year in [3, 5, 7]:
    print('YES')
else:
    print('NO')
