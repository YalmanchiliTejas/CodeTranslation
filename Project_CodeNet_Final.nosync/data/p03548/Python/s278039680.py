X, Y, Z = map(int, input().split())
ans = 0
X -= Z
while X >= Z + Y:
    X -= Z + Y
    ans += 1
print(ans)