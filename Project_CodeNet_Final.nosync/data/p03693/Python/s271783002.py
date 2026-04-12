r, g, b = map(int, input().split())
print('NO' if r * 100 + g * 10 + b & 3 else 'YES')
