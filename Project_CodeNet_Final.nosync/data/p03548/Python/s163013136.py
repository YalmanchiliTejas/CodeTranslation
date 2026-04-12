X, Y, Z = map(int, input().split())
ans = 0

X -= Z
while True:
    if X >= Y+Z:
        ans += 1
        X -= (Y+Z)
    else:
        break

print(ans)
