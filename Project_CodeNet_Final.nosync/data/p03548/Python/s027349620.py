X, Y, Z = map(int, input().split())
ans = 0
X -= Z
for _ in range(X):
    if X < (Y + Z):
        print(ans)
        break
    else:
        ans += 1
        X -= (Y + Z)
