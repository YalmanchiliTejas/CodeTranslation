X, Y, Z = map(int, input().split())
ans = 0

while X > Y + Z:
    X -= Y + Z
    ans += 1
if X < Z:
    ans -= 1
print(ans)
