r, g, b = map(int, input().split())
n = 100 * r + 10 * g + b
print('YES' if n % 4 == 0 else 'NO')