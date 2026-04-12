r, g, b = map(int, input().split())
r = r*100
g = g*10
result = r+g+b
if result%4 == 0:
    print('YES')
else:
    print('NO')