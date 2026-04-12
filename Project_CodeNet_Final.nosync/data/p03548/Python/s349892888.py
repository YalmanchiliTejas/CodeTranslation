from sys import stdin
sp = stdin.readline().split()
X, Y, Z = int(sp[0]), int(sp[1]), int(sp[2])

l = X - 2 * Z - Y
print(l // (Y + Z) + 1)