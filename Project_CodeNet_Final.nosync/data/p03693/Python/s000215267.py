# A - RGB Cards
r, g, b = [s for s in input().split()]
number = int(r + g + b)
print('YES' if number % 4 == 0 else 'NO')