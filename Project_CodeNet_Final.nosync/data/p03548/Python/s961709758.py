X, Y, Z = list(map(int, input().split()))
l = X - Y - 2 * Z
print(1 + int(l // (Y + Z)))