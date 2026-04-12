X, Y, Z = map(int, input().split())

n = 1
l = Y + 2 * Z

while X >= l:
    l += Y + Z
    n += 1

print(n-1)
