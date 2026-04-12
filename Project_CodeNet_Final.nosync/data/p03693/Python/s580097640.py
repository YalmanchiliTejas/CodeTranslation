rgb = list(input().split())
rgb = ''.join(rgb)
rgb = int(rgb)
if rgb % 4 == 0:
    print('YES')
else:
    print('NO')