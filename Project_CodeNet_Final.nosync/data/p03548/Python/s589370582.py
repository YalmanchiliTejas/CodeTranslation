X, Y, Z = map(int, input().split())
X -= (Y+Z)
ans = 1

while X >= Y+Z:
    X -= (Y+Z)
    ans += 1
if X < Z:
    ans -= 1
print(ans)