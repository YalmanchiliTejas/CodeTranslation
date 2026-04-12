r, g, b = [int(x) for x in input().split()]
print('YES' if (g * 10 + b) % 4 == 0 else 'NO')
