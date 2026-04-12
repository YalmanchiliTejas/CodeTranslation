X,Y,Z = map(int, input().split())

X -= 2*Z
ans = X // (Y+Z)
X %= (Y+Z)
if X >= Y:
    ans += 1
print(ans)