x, y, z = map(int, input().split())

ans = 0
while ans * (y + z) + z <= x:
    ans += 1
print(ans - 1)
