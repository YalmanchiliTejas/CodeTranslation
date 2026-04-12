X, Y, Z = map(int, input().split())

ans = 0
X -= Z
ans += X // (Y + Z)

print(ans)
