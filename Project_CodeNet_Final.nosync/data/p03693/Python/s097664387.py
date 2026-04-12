r, g, b = list(input().split())
print('YES' if int(r+g+b) % 4 == 0 else 'NO')