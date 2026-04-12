x, y, z = map(int, input().split())

ans = 0
x -= z
while x >= 0:
    x -= y+z
    if x >= 0: ans += 1

print(ans)