r, g, b = map(int, input().split())
A  = r * 100 + g * 10 + b
print('YES' if A % 4 == 0 else 'NO')