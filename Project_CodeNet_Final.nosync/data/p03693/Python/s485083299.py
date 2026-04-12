r, g, b = input().split()
X = int(r+g+b)%4
if (X):
    print('NO')
else:
    print('YES')
