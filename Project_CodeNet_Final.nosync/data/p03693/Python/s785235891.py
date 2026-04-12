r, g, b = map(int, input().split())
print('YES' if not (r * 100 + g * 10 + b) % 4 else 'NO')