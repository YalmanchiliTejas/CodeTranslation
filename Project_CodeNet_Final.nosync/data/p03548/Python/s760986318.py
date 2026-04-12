x, y, z = map(int, input().split())

ans = x // (y+z)
if x < ans * (y+z) + z:
    ans -= 1

print(ans)