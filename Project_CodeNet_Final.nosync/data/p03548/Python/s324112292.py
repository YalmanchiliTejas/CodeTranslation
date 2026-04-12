X, Y, Z = map(int, input().split())

rest = X - (Y + 2 * Z)
print(1 + rest // (Y + Z))