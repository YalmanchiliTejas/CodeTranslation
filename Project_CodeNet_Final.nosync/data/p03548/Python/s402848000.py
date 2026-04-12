x, y, z = map(int, input().split())

ans = 0
x -= z
ans += x // (y + z)
print(ans)