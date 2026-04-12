X,Y,Z = map(int, input().split())
X -= 2 * Z
X -= Y
ans = 0
if 0 <= X:
    ans = 1 + X // (Y + Z)

print(ans)
