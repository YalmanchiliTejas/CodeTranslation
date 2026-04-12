X, Y, Z = map(int, input().split())

n = X // (Y + Z) - 1
while X >= Y * (n + 1) + Z * (n + 2):
    n += 1
print(n)
