r, g, b = map(int, input().split())
rgb = r * 100 + g * 10 + b
print('YES' if rgb % 4 == 0 else 'NO')