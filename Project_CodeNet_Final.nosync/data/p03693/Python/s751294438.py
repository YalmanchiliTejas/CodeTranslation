r, g, b = map(int, input().split())
rgb = 100*r+10*g+b
print('YES' if rgb % 4 == 0 else 'NO')
