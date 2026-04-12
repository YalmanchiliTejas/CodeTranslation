X, Y, Z = map(int, input().split())
ans = 0
ans = X//(Y+Z)
R = X - ans * (Y + Z)
if R < Z:
    ans -= 1
print(ans)