x, y, z = [int(v) for v in input().split()]

ans = 0
x -= y + 2 * z
while x >= 0:
    ans += 1
    x -= y + z
print(ans)