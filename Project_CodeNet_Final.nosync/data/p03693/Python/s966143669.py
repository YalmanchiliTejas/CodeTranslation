r, g, b = input().split()
rgb = int(r + g + b)
print('YES') if rgb % 4 == 0 else print('NO')
