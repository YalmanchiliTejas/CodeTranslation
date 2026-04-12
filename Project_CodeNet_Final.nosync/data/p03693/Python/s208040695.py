r, g, b = map(int, input().split())
val = 100 * r + 10 * g + b
print('YES' if val % 4 == 0 else 'NO')
