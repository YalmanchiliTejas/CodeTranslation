X, Y, Z = map(int, input().split())

ans = X//(Y+Z) - 2

X -= (Y+Z)*ans

if X >= Y+2*Z:
    ans += 1
    X -= Y+2*Z
if X >= Y+Z:
    ans += 1

print(ans)
