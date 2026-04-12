X, Y, Z = list(map(int, input().split()))

if X < Y + 2 * Z:
    print(0)
else:
    x = X - (Y + 2 * Z)
    ans = int(x / (Y + Z)) + 1

print(ans)