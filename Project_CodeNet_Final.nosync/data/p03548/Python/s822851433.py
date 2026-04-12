X, Y, Z = map(int, input().split())
ans = 0
tmp = Z
while X >= tmp:
    tmp += Y + Z
    if tmp <= X:
        ans += 1

print(ans)