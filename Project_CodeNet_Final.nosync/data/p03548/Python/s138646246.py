X, Y, Z = map(int, input().split())
ans = (X - Y - 2 * Z) // (Y + Z) + 1
print(ans)