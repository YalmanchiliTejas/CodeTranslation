X, Y, Z = map(int, input().split())

n = 1
while n * Y + (n + 1) * Z <= X:
    n += 1
else:
    pass

print(str(n - 1))
