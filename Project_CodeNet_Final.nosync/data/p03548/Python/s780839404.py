x, y, z = map(int, input().split())

ans = 0
x -= z
for i in range(100000):
    if x >= y + z:
        ans += 1
        x -= y + z
    else:
        break

print(ans)