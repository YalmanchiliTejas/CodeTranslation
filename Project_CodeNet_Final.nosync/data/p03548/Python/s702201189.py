X, Y, Z = map(int, input().split())

result = X // (Y + Z) - 1
while X >= (result + 1) * Y + (result + 2) * Z:
    result += 1
print(result)
