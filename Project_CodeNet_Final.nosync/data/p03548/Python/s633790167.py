X, Y, Z = map(int, input().split())
X -= Y + 2 * Z

ans = X // (Y + Z) + 1

print(ans)