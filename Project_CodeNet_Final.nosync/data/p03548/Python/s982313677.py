X, Y, Z = map(int, input().split())
ans = 0
X -= 2 * Z
for i in range(100001):
    if X >= Y:
        ans += 1
        X -= Y + Z
    else:
        break
print(ans)
