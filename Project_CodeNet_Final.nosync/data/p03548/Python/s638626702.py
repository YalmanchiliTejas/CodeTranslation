X, Y, Z = map(int, input().split())
ans = 1
X -= (Y + 2 * Z)
if X < 0:
    print(0)
elif X == 0:
    print(1)
else:
    while X >= 0:
        X -= (Y + Z)
        if X >= 0:
            ans += 1
        else:
            break
    print(ans)